#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "Range.h"

TEST_CASE("Test Smallest Range") 
{

  std::vector<int> periodicCurrentInput {1, 2, 4};
  std:vector<ContinuityInfo> ContinuityInfoList = CalculateRangeAndReadings(periodicCurrentInput);
  assert(true == ContinuityInfoList.size());
  assert(ContinuityInfoList[0].m_totalReadingContinuousRange == 2);
}