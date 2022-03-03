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