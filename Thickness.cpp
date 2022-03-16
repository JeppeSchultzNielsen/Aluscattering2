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
    double_t E[100];
    double_t scatterAngle[100];
    UInt_t BI[100];
    UInt_t FI[100];
    UInt_t id[100];
    UInt_t mul;
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
            UInt_t currentFI = 0;
            UInt_t currentBI = 0;
            UInt_t currentid = 0;
            currentAngle += scatterAngle[j];
            currentFI += FI[j];
            currentBI += BI[j];
            currentid += id[j];
            auto boolAndIndex = findPixel(pixelInfo,currentFI, currentBI, currentid, lastPrinted);
            //case for hvis der endnu ikke findes et histogram for denne pixel.
            if(!get<0>(boolAndIndex)){
                //skab nyt histogram til at indeholde events ved denne vinkel
                sprintf(name,"%f",currentAngle);
                sprintf(title,"%f",currentAngle);
                histograms[lastPrinted] = new TH1I(name, title, energy, 0.0, energy-1);
                //læg vinklen ind i vinkelarray ved samme index
                angles[lastPrinted] = currentAngle;
                //fyld energien ind i det skabte histogram
                histograms[lastPrinted] -> Fill(E[j]);
                //læg en til lastPrinted, så vi er klar til næste gang der er en ny vinkel
                lastPrinted ++;
                //printf(angleString);
            }
            else{
                //der fandtes allerede et histogram for denne vinkel.
                histograms[get<1>(boolAndIndex)] -> Fill(E[j]);
            }
        }
    }
}