#pragma once
#include <vector>

using namespace std;

struct ContinuityInfo
{
	int m_startIndexValueOfContinuousRange;
	int m_endIndexValueOfContinuousRange;
	int m_totalReadingContinuousRange;
	
	ContinuityInfo()
	: m_startIndexValueOfContinuousRange(0)
	, m_endIndexValueOfContinuousRange(0)
	, m_totalReadingContinuousRange(0)
	{
	}
};

std::vector<ContinuityInfo> CalculateRangeAndReadings(std::vector<int> periodicCurrentVector);
void checkForContinuityInPeriodicCurrent(std::vector<int> periodicCurrentVector, int CurrentIndexInPeriodicCurrentVector, ContinuityInfo& continuityInfo);
bool isValueContinuous(int currentIndexValue, int followingIndexValue);