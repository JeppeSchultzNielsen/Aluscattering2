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
#include "include/runner.h"
#include <regex>
#include <array>
#include <iterator>
#include <TGraph.h>
#include <TMultiGraph.h>

using namespace std;
using namespace AUSA;
using namespace ROOT::Math;
using namespace AUSA::EnergyLoss;
using namespace ROOT;

vector<double> findCurrent(string in){
    string energy = regex_replace(in, regex(R"([\D])"), "");
    string analyzed = "Al"+regex_replace(in, regex(R"([\D])"), "") + ".root";
    TFile *myFile = TFile::Open(analyzed.c_str());
    TTree *t = (TTree*)myFile->Get("h101");

    UInt_t vcharge;
    UInt_t clock;
    t ->SetBranchAddress("VCHARGE",&vcharge);
    t ->SetBranchAddress("CLOCK",&clock);

    t->GetEntry(0);
    UInt_t firstClock = clock;
    double firstCharge = vcharge;

    UInt_t entries = t -> GetEntries();

    t->GetEntry(entries - 1);

    UInt_t stepCharge;
    UInt_t lastClock = 0;
    UInt_t lastCharge;
    UInt_t stepClock;
    stepClock += 38227290460;

    auto gr = new TGraph();

    for(int i = 0; i < entries; i++){
        t->GetEntry(i);
        if(vcharge > 0){
            gr -> AddPoint(clock, vcharge);
        }
        if(vcharge > firstCharge + 20){
            if(lastClock < clock){
                lastClock = clock;
                lastCharge = vcharge;
            }
            if(stepClock > clock){
                stepClock = clock;
                stepCharge = vcharge;
            }
        }
    }

    double deltaCharge = lastCharge - stepCharge;
    double deltaClock =  lastClock - stepClock;
    double_t current = deltaCharge/(deltaClock);
    double_t offset = firstCharge - stepClock*current;

    cout << current << endl;

    cout << offset << endl;


    auto gr2 = new TGraph();
    for(UInt_t i = firstClock; i < (lastClock + 1000); i=i+1000){
        gr2 ->AddPoint(i,offset + current*i);
    }

    TMultiGraph *mg = new TMultiGraph();
    mg->Add(gr);
    mg->Add(gr2);
    string histRoot = "currentGraphs/" + energy + "clockvscharge.root";
    TFile output(histRoot.c_str(), "RECREATE");

    output.cd();
    mg -> Write();

    return {deltaClock, deltaCharge};
}