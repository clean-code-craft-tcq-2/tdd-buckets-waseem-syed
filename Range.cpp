#include "Range.h"
#include <algorithm> 
#include <iostream>

bool isValueContinuous(int currentIndexValue, int followingIndexValue)
{
   if(((followingIndexValue - currentIndexValue) == 1) || ((followingIndexValue - currentIndexValue) == 0))//Continuous element or same element
   {
	   return true;
   }
   return false;
}

void sortedPeriodicCurrents(std::vector<int> periodicCurrentVector, int CurrentIndexInPeriodicCurrentVector, ContinuityInfo& continuityInfo)
{
	int startIndex = periodicCurrentVector[CurrentIndexInPeriodicCurrentVector];
   for(int index = CurrentIndexInPeriodicCurrentVector; index < (periodicCurrentVector.size() - 1); index++)
   {
	   if(isValueContinuous(periodicCurrentVector[index], periodicCurrentVector[index + 1]))
	   {
		   continuityInfo.m_totalReadingContinuousRange ++;
		   continuityInfo.m_startIndexValueOfContinuousRange = startIndex;
		   continuityInfo.m_endIndexValueOfContinuousRange = periodicCurrentVector[index + 1];
	   }
	   else
	   {
		   break;
	   }
   }
}

std::vector<ContinuityInfo> CalculateRangeAndReadings(std::vector<int> periodicCurrentVector)
{
    int CurrentIndexInPeriodicCurrentVector = 0;
	std::vector<ContinuityInfo> continuityInfoList;
	std::sort(periodicCurrentVector.begin(), periodicCurrentVector.end());
    while(true == (CurrentIndexInPeriodicCurrentVector < periodicCurrentVector.size()))
	{
	   ContinuityInfo continuityInfo;
           sortedPeriodicCurrents(periodicCurrentVector, CurrentIndexInPeriodicCurrentVector, continuityInfo);
	   if(continuityInfo.m_totalReadingContinuousRange > 1)
	   {
		  continuityInfoList.push_back(continuityInfo);
	      CurrentIndexInPeriodicCurrentVector = CurrentIndexInPeriodicCurrentVector + continuityInfo.m_totalReadingContinuousRange - 1;
	   }
	   CurrentIndexInPeriodicCurrentVector++;
	}
	return continuityInfoList;
}
