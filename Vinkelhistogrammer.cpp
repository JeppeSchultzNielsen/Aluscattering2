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

using namespace std;
using namespace AUSA;
using namespace ROOT::Math;
using namespace AUSA::Sort;
using namespace AUSA::EnergyLoss;
using namespace AUSA::Constants;
using namespace libconfig;


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

    //Lav et histogram
    TH1* h1 = new TH1I("h1", "Histogram ved scatteringangle 80 grader", 2000, 0.0, 12000);
    for (Int_t i=0; i<entries; i++){
        t->GetEntry(i);
        for(Int_t j=0; j<mul; j++) {
            if (scatterAngle[j] > 80 && scatterAngle[j] < 81) {
                h1->Fill(E[j]);
            } else {};
        }
    }
    //Fit 4 Gausser til det.
    TF1  *f1 = new TF1("f1","sin(x)/x",0,10);
}