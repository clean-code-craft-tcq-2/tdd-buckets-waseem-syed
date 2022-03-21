#pragma once
#include <vector>

using namespace std;

struct ContinuityInfo
{
	int m_startIndexOfContinuousRange;
	int m_endIndexOfContinuousRange;
	int m_totalReadingContinuousRange;
	
	ContinuityInfo()
	: m_startIndexOfContinuousRange(0)
	, m_endIndexOfContinuousRange(0)
	, m_totalReadingContinuousRange(0)
	{
	}
};

std::vector<ContinuityInfo> CalculateRangeAndReadings(std::vector<int> periodicCurrentVector);
void checkForContinuityInPeriodicCurrent(std::vector<int> periodicCurrentVector, int CurrentIndexInPeriodicCurrentVector, ContinuityInfo& continuityInfo);