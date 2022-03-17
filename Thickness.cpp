#include <iostream>
#include <string>
#include <ausa/util/FileUtil.h>
#include <ausa/util/DynamicBranchVector.h>
#include <ausa/eloss/Default.h>
#include <Math/Vector3D.h>
#include <TROOT.h>
#include "TH1.h"
#include "TF1.h"
#include "TSpectrum.h"
#include <fstream>
#include "TFitResult.h"
#include <regex>
#include <Math/Vector3D.h>
#include <TROOT.h>
#include <TVector3.h>
#include <include/runner.h>

using namespace std;
using namespace AUSA;
using namespace ROOT::Math;
using namespace AUSA::EnergyLoss;
using namespace ROOT;

//løber igennem listen af angles og returnerer true hvis vinklen er i listen
tuple<bool,int> findPixel(UInt_t toSearch[1000][3], UInt_t FI, UInt_t BI, UInt_t id, int loopuntil){
    for (int i = 0; i<loopuntil; i++){
        if(toSearch[i][0] == FI && toSearch[i][1] == BI && toSearch[i][2] == id){
            return make_tuple(true,i);
        }
    }
    return make_tuple(false,-1);
}

double thickness(string in){
    //energien denne fil blev optaget ved er givet i dens titel
    int energy = stoi(regex_replace(in, regex(R"([\D])"), ""));
    //skab en pointer til root-filen der er blevet lavet af analyse.
    string analyzed = "analyzed/"+regex_replace(in, regex(R"([\D])"), "") + "a.root";
    TFile *myFile = TFile::Open(analyzed.c_str());
    //Hent træet
    TTree *t = (TTree*)myFile->Get("a");

    //Skab variable som værdier kan loades ned i. Associer dem med branches i træet, så den i. entry bliver lagt
    //deri når vi kalder getEntry(i). Print antallet af entries i træet.
    double_t E[10];
    double_t scatterAngle[10];
    UInt_t BI[10];
    UInt_t FI[10];
    UInt_t id[10];
    double_t posx[10];
    double_t posy[10];
    double_t posz[10];

    double_t dirx[10];
    double_t diry[10];
    double_t dirz[10];
    UInt_t mul;
    t->SetBranchAddress("pos.fX",&posx);
    t->SetBranchAddress("pos.fY",&posy);
    t->SetBranchAddress("pos.fZ",&posz);

    t->SetBranchAddress("dir.fX",&dirx);
    t->SetBranchAddress("dir.fY",&diry);
    t->SetBranchAddress("dir.fZ",&dirz);
    t->SetBranchAddress("id",&id);
    t->SetBranchAddress("BI",&BI);
    t->SetBranchAddress("FI",&FI);
    t->SetBranchAddress("E",&E);
    t->SetBranchAddress("scatterAngle",&scatterAngle);
    t->SetBranchAddress("mul",&mul);
    auto entries = t->GetEntries();
    cout << "Energy: " << energy << "keV " << endl;
    cout << "Entries: " << entries << endl;

    //skriv peak positioner til en .txt fil

    //Lav et array af histogrammer og vinkler på tilsvarende indekser
    TH1I *histograms[1000] = {};
    double_t angles[1000] = {};
    UInt_t pixelInfo[1000][3] = {};
    vector<double_t> positions[1000] = {};
    vector<double_t> directions[1000] = {};

    int lastPrinted = 0;
    for (Int_t i = 0; i < entries; i++) {
        if(i%300000 == 0){
            cout << "Finding 110 degrees in " << energy << "keV data: " << float(i)/float(entries)*100<< "%" << " \r";
            cout.flush();
        }

        //hent entry
        t->GetEntry(i);
        //loop over alle hits i denne entry
        for (Int_t j = 0; j < mul; j++) {
            //hvis vi ikke har set denne vinkel før skal vi lave et nyt histogram for denne vinkel.
            double currentAngle = 0;
            currentAngle += scatterAngle[j];
            //vi gider kun at bruge dem der er scatteret ved ca. 110 grader.
            if(fabs(currentAngle - 110) < 0.5) {
                short currentFI = 0;
                short currentBI = 0;
                short currentid = 0;
                double currentE = 0;
                vector<double_t> currentPos = {};
                currentPos = {posx[j],posy[j],posz[j]};
                vector<double_t> currentDir = {};
                currentDir = {dirx[j],diry[j],dirz[j]};
                currentFI += FI[j];
                currentBI += BI[j];
                currentid += id[j];
                currentE += E[j];
                auto boolAndIndex = findPixel(pixelInfo, currentFI, currentBI, currentid, lastPrinted+1);
                //case for hvis der endnu ikke findes et histogram for denne pixel.
                if (!get<0>(boolAndIndex)) {
                    //skab nyt histogram til at indeholde events ved denne vinkel
                    string name = "ID: " + to_string(currentid) + " FI: " + to_string(currentFI) + " BI: " +
                                  to_string(currentBI) + " angle: " + to_string(currentAngle);
                    histograms[lastPrinted] = new TH1I(name.c_str(), name.c_str(), energy, 0.0, energy - 1);
                    //læg vinklen ind i vinkelarray ved samme index
                    angles[lastPrinted] = currentAngle;
                    pixelInfo[lastPrinted][0] = currentFI;
                    pixelInfo[lastPrinted][1] = currentBI;
                    pixelInfo[lastPrinted][2] = currentid;
                    positions[lastPrinted] = currentPos;
                    directions[lastPrinted] = currentDir;
                    //fyld energien ind i det skabte histogram
                    histograms[lastPrinted]->Fill(currentE);
                    //læg en til lastPrinted, så vi er klar til næste gang der er en ny vinkel
                    lastPrinted++;
                    //printf(angleString);
                } else {
                    //der fandtes allerede et histogram for dette pixel
                    histograms[get<1>(boolAndIndex)]->Fill(currentE);
                }
            }
        }
    }
    string histRoot = "summedhistograms.root";
    TH1I *summedHist = new TH1I("summed", "summed", energy, 0.0, energy - 1);
    TFile output(histRoot.c_str(), "RECREATE");
    for(int i = 0; i < lastPrinted; i++){
        TH1I *currentHist = histograms[i];
        if(currentHist -> GetEntries() > 100){
            summedHist -> Add(currentHist);
        }
    }
    output.cd();
    summedHist -> Write();
    unique_ptr<EnergyLossRangeInverter> SiCalc = defaultRangeInverter("p", "Aluminium");
    cout << SiCalc -> getTotalEnergyCorrection(1920,0.0012) << endl;
}