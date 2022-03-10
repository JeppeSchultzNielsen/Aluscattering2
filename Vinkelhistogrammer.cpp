#include <iostream>
#include <string>
#include <ausa/json/IO.h>
#include <ausa/sort/analyzer/AbstractSortedAnalyzer.h>
#include <ausa/sort/SortedReader.h>
#include <ausa/util/StringUtil.h>
#include <ausa/util/FileUtil.h>
#include <ausa/setup/DoubleSidedSiliconDetector.h>
#include <ausa/setup/SingleSidedSiliconDetector.h>
#include <ausa/util/DynamicBranchVector.h>
#include <ausa/eloss/Ion.h>
#include <ausa/eloss/Default.h>
#include <ausa/constants/Mass.h>
#include <ausa/output/OutputConvenience.h>
#include <Math/Vector3D.h>
#include <TROOT.h>
#include <ctime>
#include <libconfig.h++>
#include "include/Hit.h"
#include "TH1.h"
#include "TF1.h"
#include "TSpectrum.h"
#include <iostream>
#include <fstream>
#include "TVirtualFitter.h"
#include "TCanvas.h"
#include "TFitResult.h"

using namespace std;
using namespace AUSA;
using namespace ROOT::Math;
using namespace AUSA::Sort;
using namespace AUSA::EnergyLoss;
using namespace AUSA::Constants;
using namespace libconfig;
using namespace ROOT;

double gaussSum(double *x, double *par){
    int npeaks = par[0];
    double_t result = 0;
    for (Int_t p=0;p<npeaks;p++) {
        Double_t norm = par[3 * p+1]; // "height" or "area"
        Double_t mean = par[3 * p + 2];
        Double_t sigma = par[3 * p + 3];
        result += norm*TMath::Gaus(x[0],mean,sigma);
    }
    return result;
}

bool AreSame(double a, double b)
{
    return fabs(a - b) < 0.5;
}

//løber igennem listen af angles og returnerer true hvis vinklen er i listen
tuple<bool,int> findAngle(double toSearch[], double angle){
    double arraySize = 10000;
    for (int i = 0; i<arraySize; i++){
        if(AreSame(toSearch[i],angle)){
            return make_tuple(true,i);
        }
    }
    return make_tuple(false,-1);
}

int main(int argc, char *argv[]){
    //skab en pointer til den rootfil, jeg lige har lavet.
    TFile *myFile = TFile::Open("lio.root");
    //Hent træet
    TTree *t = (TTree*)myFile->Get("a");

    //Skab variable som værdier kan loades ned i. Associer dem med branches i træet, så den i. entry bliver lagt
    //deri når vi kalder getEntry(i). Print antallet af entries i træet.
    double_t E[100];
    double_t scatterAngle[100];
    UInt_t mul;
    t->SetBranchAddress("E",&E);
    t->SetBranchAddress("scatterAngle",&scatterAngle);
    t->SetBranchAddress("mul",&mul);
    auto entries = t->GetEntries();
    cout << "Entries: " << entries << endl;

    //skriv peak positioner til en .txt fil
    ofstream myfile ("peakpositioner.txt");
    myfile << "Theta\tE\n";

    //Lav et array af histogrammer og vinkler på tilsvarende indekser
    int arraySize = 10000;
    TH1I *histograms[arraySize];
    double_t angles[arraySize];
    int lastPrinted = 0;

    char name[120];
    char title[120];

    //loop over alle entries i root filen
    for (Int_t i = 0; i < entries; i++) {
        if(i%100000 == 0){
            cout << "i: " << i << endl;
        }

        //hent entry
        t->GetEntry(i);
        //loop over alle hits i denne entry
        for (Int_t j = 0; j < mul; j++) {
            //hvis vi ikke har set denne vinkel før skal vi lave et nyt histogram for denne vinkel.
            double currentAngle = 0;// scatterAngle[j];
            currentAngle += scatterAngle[j];
            auto boolAndIndex = findAngle(angles,currentAngle);
            if(!get<0>(boolAndIndex)){
                //skab nyt histogram til at indeholde events ved denne vinkel
                sprintf(name,"%f",currentAngle);
                sprintf(title,"%f",currentAngle);
                histograms[lastPrinted] = new TH1I(name, title, 2000, 0.0, 1999);
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
    cout << "Lastangle: " << lastPrinted << endl;
    cout << "Lastangle: " << angles[7] << endl;
    int nconverged = 0;
    int ntot = 0;
    //nu skal jeg finde peaks i alle histogrammerne. Jeg looper over histogrammerne:
    for(int i = 0; i < lastPrinted; i++) {
        //Find peaks med inspiration fra https://root.cern/doc/master/peaks_8C.html
        //TSpectrum kan finde peaks
        TH1I *currentHist = histograms[i];

        //vi vil kun gøre det følgende, hvis vi har mere end 1000 entries i histogrammet, ellers giver det ikke
        //rigtigt mening.
        if (currentHist->GetEntries() > 1000) {
            ntot += 1;
            auto *s = new TSpectrum(100);
            Int_t nfound = s->Search(currentHist, 10, "", 0.1);

            auto xpeaks = s->GetPositionX();

            //For hvert peak skal jeg bruge 3 parametre til at bestemme en gauss. (og så skal jeg give en mere til
            //funktionen for at fortælle den, hvor mange peaks der er, men den fixes til npeaks).
            double par[nfound * 3 + 1];
            //gider ikke dem der har mange peaks
            if (nfound < 8) {
                for (int p = 0; p < nfound; p++) {
                    Double_t xp = xpeaks[p];
                    Int_t bin = currentHist->GetXaxis()->FindBin(xp);
                    Double_t yp = currentHist->GetBinContent(bin);
                    par[1 + 3 * p] = 3 * yp;
                    par[2 + 3 * p] = xp;
                    par[3 + 3 * p] = 20;
                    myfile << to_string(angles[i]) + "\t" + to_string(xp) + "\n";
                }
                TF1 *fit = new TF1("fit", gaussSum, 0, 2000, 1 + 3 * nfound);
                //TVirtualFitter tillader vist at vi kan have flere parametre?
                //TVirtualFitter::Fitter(currentHist,10+3*nfound);
                fit->SetParameters(par);
                fit->FixParameter(0, nfound);
                fit->SetNpx(2000);
                TFitResultPtr fp = currentHist->Fit("fit","s && Q");
                if (fp->IsValid()) {
                    nconverged += 1;
                    for (int k = 0; k < nfound; k++) {
                        myfile << to_string(angles[i]) + "\t" + to_string(fit->GetParameter(2 + 3 * k)) + "\n";
                    }
                }
                //vi kan lige gemme et histogram hvis det er
                if (i == 148) {
                    TFile output("file.root", "RECREATE");
                    output.cd();
                    currentHist->Write();
                }
            }
        }
    }
    cout << "Converged: " << nconverged << endl;
    cout << "Total: " << ntot << endl;
    myfile.close();
}