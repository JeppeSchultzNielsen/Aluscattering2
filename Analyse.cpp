#include <iostream>
#include <ausa/json/IO.h>
#include <memory>
#include <ausa/util/Resource.h>
#include <ausa/eloss/Util.h>
#include <ausa/sort/SortedReader.h>
#include <ausa/sort/analyzer/AbstractSortedAnalyzer.h>
#include <ausa/calibration/peakfinder/SimplePeakFinder.h>
#include <ausa/calibration/peakfinder/GaussianMultiPeakFinder.h>
#include <TH2.h>

using namespace std;
using namespace AUSA;
using namespace AUSA::Sort;
using namespace AUSA::Calibration;

class MyAnalysis : public AbstractSortedAnalyzer {
public:
    void setup(const SortedSetupOutput &output) override {

    }


    void analyze() override {

    }

    void doAnalysis() {

    }

    void terminate() override {

    }
};


int main(int argc, char *argv[]) {
    auto setup = JSON::readSetupFromJSON("setup/setup.json");
    auto target = JSON::readTargetFromJSON("target.json");

    string in = argv[1];

    SortedReader reader{*setup};
    reader.add(in);
    reader.setVerbose(true);

    auto analysis = make_shared<MyAnalysis>();
    reader.attach(analysis);
    reader.run();

    return 0;
}