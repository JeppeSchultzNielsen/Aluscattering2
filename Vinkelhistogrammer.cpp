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
    double E[10];
    double scatterAngle[10];
    t->SetBranchAddress("E",&E);
    t->SetBranchAddress("scatterAngle",&scatterAngle);
    auto entries = t->GetEntries();
    cout << "Entries: " << entries << endl;

    //Lav et histogram
    TH1* h1 = new TH1I("h1", "Histogram ved scatteringangle 80 grader", 2000, 0.0, 12000);
    cout << "Entries: " << entries << endl;
    for (Int_t i=0; i<entries; i++){
        t->GetEntry(i);
        cout << "I " << i << endl;
        //problem: Hvad hvis der er flere hits indeni dette leaf?
        if(scatterAngle[0]>80 && scatterAngle[0]<81){
            h1->Fill(E[0]);
        }
        else{};
    }
    h1->Draw();
}