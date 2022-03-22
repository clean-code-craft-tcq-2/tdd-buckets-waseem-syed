#include "Range.h"

bool isValueContinuous(int currentIndexValue, int followingIndexValue)
{
   if(((currentIndexValue - followingIndexValue) == 1) || ((followingIndexValue - currentIndexValue) == 1))
   {
	   return true;
   }
   return false;
}

void checkForContinuityInPeriodicCurrent(std::vector<int> periodicCurrentVector, int CurrentIndexInPeriodicCurrentVector, ContinuityInfo& continuityInfo)
{
	int startIndex = periodicCurrentVector[CurrentIndexInPeriodicCurrentVector];
   for(int index = CurrentIndexInPeriodicCurrentVector; CurrentIndexInPeriodicCurrentVector <= (periodicCurrentVector.size() - 1); CurrentIndexInPeriodicCurrentVector++)
   {
	   if(isValueContinuous(periodicCurrentVector[CurrentIndexInPeriodicCurrentVector], periodicCurrentVector[CurrentIndexInPeriodicCurrentVector + 1]))
	   {
		   continuityInfo.m_totalReadingContinuousRange ++;
		   continuityInfo.m_startIndexValueOfContinuousRange = startIndex;
		   continuityInfo.m_endIndexValueOfContinuousRange = periodicCurrentVector[CurrentIndexInPeriodicCurrentVector + 1];
		   CurrentIndexInPeriodicCurrentVector++;
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
    while(true == (CurrentIndexInPeriodicCurrentVector < periodicCurrentVector.size()))
	{
	   ContinuityInfo continuityInfo;
       checkForContinuityInPeriodicCurrent(periodicCurrentVector, CurrentIndexInPeriodicCurrentVector, continuityInfo);
	   if(continuityInfo.m_totalReadingContinuousRange > 1)
	   {
		  continuityInfoList.push_back(continuityInfo);
	      CurrentIndexInPeriodicCurrentVector = continuityInfo.m_endIndexValueOfContinuousRange;
	   }
	   CurrentIndexInPeriodicCurrentVector++;
	}
	return continuityInfoList;
}