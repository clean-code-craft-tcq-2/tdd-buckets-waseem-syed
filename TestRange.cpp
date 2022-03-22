#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "Range.h"

TEST_CASE("Test CalculateRangeAndReadings") 
{

  std::vector<int> periodicCurrentInput {1, 2, 4};
  std::vector<ContinuityInfo> ContinuityInfoList;
  ContinuityInfoList = CalculateRangeAndReadings(periodicCurrentInput);
  assert(true == ContinuityInfoList.size());
  REQUIRE(ContinuityInfoList[0].m_totalReadingContinuousRange == 2);
}

TEST_CASE("Test checkForContinuityInPeriodicCurrent")
{
   std::vector<int> periodicCurrentInput {1, 2, 4};
   int CurrentIndexInPeriodicCurrentVector = 0;
   ContinuityInfo continuityInfo;
   checkForContinuityInPeriodicCurrent(periodicCurrentInput, CurrentIndexInPeriodicCurrentVector, continuityInfo);
   REQUIRE(continuityInfo.m_totalReadingContinuousRange == 2);
}

TEST_CASE("Test isValueContinuous")
{
	int currentIndexValue = 5;
	int followingIndexValue = 7;
	REQUIRE(false == (isValueContinuous(currentIndexValue, followingIndexValue);
}