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
  REQUIRE(ContinuityInfoList[0].m_startIndexValueOfContinuousRange == 1);
  REQUIRE(ContinuityInfoList[0].m_endIndexValueOfContinuousRange == 2);
	
  ::std::vector<int> periodicCurrentInput1 {3, 3, 5, 4, 10, 11, 12};
  std::vector<ContinuityInfo> ContinuityInfoList1;
  ContinuityInfoList1 = CalculateRangeAndReadings(periodicCurrentInput1);
  assert(2 == ContinuityInfoList1.size());
  REQUIRE(ContinuityInfoList1[0].m_totalReadingContinuousRange == 4);
  REQUIRE(ContinuityInfoList1[0].m_startIndexValueOfContinuousRange == 3);
  REQUIRE(ContinuityInfoList1[0].m_endIndexValueOfContinuousRange == 5);
  REQUIRE(ContinuityInfoList1[1].m_totalReadingContinuousRange == 3);
  REQUIRE(ContinuityInfoList1[1].m_startIndexValueOfContinuousRange == 10);
  REQUIRE(ContinuityInfoList1[1].m_endIndexValueOfContinuousRange == 12);
}

TEST_CASE("Test checkForContinuityInPeriodicCurrent")
{
   std::vector<int> periodicCurrentInput {1, 2, 4};
   int CurrentIndexInPeriodicCurrentVector = 0;
   ContinuityInfo continuityInfo;
   checkForContinuityInPeriodicCurrent(periodicCurrentInput, CurrentIndexInPeriodicCurrentVector, continuityInfo);
   REQUIRE(continuityInfo.m_totalReadingContinuousRange == 2);
   REQUIRE(continuityInfo.m_startIndexValueOfContinuousRange == 1);
   REQUIRE(continuityInfo.m_endIndexValueOfContinuousRange == 2);  
}

TEST_CASE("Test isValueContinuous")
{
	int currentIndexValue = 5;
	int followingIndexValue = 7;
	REQUIRE(false == (isValueContinuous(currentIndexValue, followingIndexValue)));
}
