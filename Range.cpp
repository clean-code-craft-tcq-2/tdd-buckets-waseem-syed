#include "Range.h"

void checkForContinuityInPeriodicCurrent(std::vector<int> periodicCurrentVector, int CurrentIndexInPeriodicCurrentVector, ContinuityInfo& continuityInfo)
{
	continuityInfo.m_totalReadingContinuousRange = 2;
	continuityInfo.m_startIndexOfContinuousRange = 0;
	continuityInfo.m_endIndexOfContinuousRange = 1;
}

std:vector<ContinuityInfo> CalculateRangeAndReadings(std::vector<int> periodicCurrentVector)
{
    int CurrentIndexInPeriodicCurrentVector = 0;
	std:vector<ContinuityInfo> continuityInfoList;
    while(true == (CurrentIndexInPeriodicCurrentVector < periodicCurrentVector.size()))
	{
	   ContinuityInfo continuityInfo;
       checkForContinuityInPeriodicCurrent(periodicCurrentVector, CurrentIndexInPeriodicCurrentVector, continuityInfo);
	   if(continuityInfo.m_totalReadingContinuousRange != 0)
	   {
		  continuityInfoList.push_back(continuityInfo);
	      CurrentIndexInPeriodicCurrentVector = continuityInfo.m_endIndexOfContinuousRange;
	   }
	   CurrentIndexInPeriodicCurrentVector++;
	}
	return continuityInfoList;
}