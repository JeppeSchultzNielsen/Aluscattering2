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

using namespace std;
using namespace AUSA;
using namespace ROOT::Math;
using namespace AUSA::Sort;
using namespace AUSA::EnergyLoss;
using namespace AUSA::Constants;
using namespace libconfig;
using namespace ROOT;

double gauss4(double *x, double *par){
    double fitval = par[0]*Math::exp(-(x[0]-par[1])*(x[0]-par[1])/par[2])+
            par[3]*Math::exp(-(x[0]-par[4])*(x[0]-par[4])/par[5])+
            par[6]*Math::exp(-(x[0]-par[7])*(x[0]-par[7])/par[8]);
    return fitval;
}

int main(int argc, char *argv[]){
    //skab en pointer til den rootfil, jeg lige har lavet.
    TFile *myFile = TFile::Open("lio.root");
    //Hent træet
    TTree *t = (TTree*)myFile->Get("a");

    //Skab variable som værdier kan loades ned i. Associer dem med branches i træet, så den i. entry bliver lagt
    //deri når vi kalder getEntry(i). Print antallet af entries i træet.
    double E[100];
    double scatterAngle[100];
    UInt_t mul;
    t->SetBranchAddress("E",&E);
    t->SetBranchAddress("scatterAngle",&scatterAngle);
    t->SetBranchAddress("mul",&mul);
    auto entries = t->GetEntries();
    cout << "Entries: " << entries << endl;

    //skriv peak positioner til en .txt fil
    ofstream myfile ("peakpositioner.txt");
    myfile << "Theta\tE\n";

    Int_t start = 60;
    Int_t end = 120;
    double step = 0.5;

    //Lav et histogram
    TH1 *h1 = new TH1I("h1", "Histogram ved scatteringangle 80 grader", 2000, 0.0, 1999);

    //loop over alle vinkler
    for(double run = start; run<end; run += step) {
        for (Int_t i = 0; i < entries; i++) {
            t->GetEntry(i);
            for (Int_t j = 0; j < mul; j++) {
                if (scatterAngle[j] > run && scatterAngle[j] < run+step) {
                    h1->Fill(E[j]);
                }
            }
        }
        //Find peaks med inspiration fra https://root.cern/doc/master/peaks_8C.html
        //TSpectrum kan finde peaks
        auto *s = new TSpectrum(100);
        Int_t nfound = s->Search(h1, 2.5, "", 0.05);

        //gem de gældende peaks
        auto xpeaks = s->GetPositionX();
        for (int p = 0; p < nfound; p++) {
            Double_t xp = xpeaks[p];
            myfile << to_string(run) + "\t" + to_string(xp) + "\n";
        }
        cout << "Run: " << run << endl;
        h1->Reset();
    }
    myfile.close();
}