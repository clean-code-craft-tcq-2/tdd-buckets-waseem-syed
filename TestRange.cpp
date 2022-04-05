#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "Range.h"
#include "A2DConverter.h"

TEST_CASE("Test CalculateRangeAndReadings Continuous Reading present, Expect continuityInfo filled properly") 
{

  std::vector<int> periodicCurrentInput {1, 2, 4};
  std::vector<ContinuityInfo> ContinuityInfoList;
  ContinuityInfoList = CalculateRangeAndReadings(periodicCurrentInput);
  assert(1 == ContinuityInfoList.size());
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

TEST_CASE("Test CalculateRangeAndReadings No Continuous reading, Expect empty continuityInfo ")
{
  std::vector<int> periodicCurrentInput2 {1, 3, 5};
  std::vector<ContinuityInfo> ContinuityInfoList2;
  ContinuityInfoList2 = CalculateRangeAndReadings(periodicCurrentInput2);
  assert(0 == ContinuityInfoList2.size());
}


TEST_CASE("Test checkForContinuityInPeriodicCurrent positive")
{
   std::vector<int> sortedPeriodicCurrents {1, 2, 4};
   int CurrentIndexInPeriodicCurrentVector = 0;
   ContinuityInfo continuityInfo;
   checkForContinuityInPeriodicCurrent(sortedPeriodicCurrents, CurrentIndexInPeriodicCurrentVector, continuityInfo);
   checkForContinuityInPeriodicCurrent(periodicCurrentInput, CurrentIndexInPeriodicCurrentVector, continuityInfo);
   REQUIRE(continuityInfo.m_totalReadingContinuousRange == 2);
   REQUIRE(continuityInfo.m_startIndexValueOfContinuousRange == 1);
   REQUIRE(continuityInfo.m_endIndexValueOfContinuousRange == 2);  
}

TEST_CASE("Test checkForContinuityInPeriodicCurrent Negative")
{
   std::vector<int> sortedPeriodicCurrents {1, 2, 4};
   int CurrentIndexInPeriodicCurrentVector = 1;
   ContinuityInfo continuityInfo1;
   checkForContinuityInPeriodicCurrent(sortedPeriodicCurrents, CurrentIndexInPeriodicCurrentVector, continuityInfo1);
   //default values
   REQUIRE(continuityInfo1.m_totalReadingContinuousRange == 1);
   REQUIRE(continuityInfo1.m_startIndexValueOfContinuousRange == 0);
   REQUIRE(continuityInfo1.m_endIndexValueOfContinuousRange == 0); 
}

TEST_CASE("Test isValueContinuous Positive")
{
	int currentIndexValue = 5;
	int followingIndexValue = 5;
	REQUIRE(true == (isValueContinuous(currentIndexValue, followingIndexValue)));

	currentIndexValue = 5;
	followingIndexValue = 6;
	REQUIRE(true == (isValueContinuous(currentIndexValue, followingIndexValue)));
}

TEST_CASE("Test isValueContinuous Negative")
{
	int currentIndexValue = 5;
	int followingIndexValue = 7;
	REQUIRE(false == (isValueContinuous(currentIndexValue, followingIndexValue)));
}

//Test AToD cpnverter implementation

TEST_CASE("Test ConvertAmpsListFromAToD Positive") 
{
   std::vector<int> ampsInAnalog {4094, 4000};
   std::vector<int> ampsInDigital = ConvertAmpsListFromAToD(ampsInAnalog);
   assert(false == ampsInDigital.empty());
   REQUIRE(ampsInDigital[0] == 10);
   REQUIRE(ampsInDigital[1] == 10);
}

TEST_CASE("Test ConvertAmpsListFromAToD Negative") 
{
   std::vector<int> ampsInAnalog {0, 4095};
   std::vector<int> ampsInDigital = ConvertAmpsListFromAToD(ampsInAnalog);
   assert(true == ampsInDigital.empty());
}

TEST_CASE("Test getAmpsInDigital")
{
	int ampsInAnalog = 4094;
	REQUIRE((getAmpsInDigital(ampsInAnalog)) == 10);
	
	ampsInAnalog = 1146;
	REQUIRE((getAmpsInDigital(ampsInAnalog)) == 3);
}
