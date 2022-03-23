#include "Range.h"
#include <algorithm> 
#include <iostream>

bool isValueContinuous(int currentIndexValue, int followingIndexValue)
{
   ::std::cout<<"isValueContinuous : 7\n";
   if(((currentIndexValue - followingIndexValue) == 1) || ((currentIndexValue - followingIndexValue) == 0))//Continuous element or same element
   {
	      ::std::cout<<"isValueContinuous : 10\n";
	   return true;
   }
   return false;
}

void checkForContinuityInPeriodicCurrent(std::vector<int> periodicCurrentVector, int CurrentIndexInPeriodicCurrentVector, ContinuityInfo& continuityInfo)
{
	   ::std::cout<<"checkForContinuityInPeriodicCurrent : 18\n";
	int startIndex = periodicCurrentVector[CurrentIndexInPeriodicCurrentVector];
   for(int index = CurrentIndexInPeriodicCurrentVector; index <= (periodicCurrentVector.size() - 1); index++)
   {
	   	   ::std::cout<<"checkForContinuityInPeriodicCurrent : 22\n";
	   if(isValueContinuous(periodicCurrentVector[index], periodicCurrentVector[index + 1]))
	   {
		   ::std::cout<<"checkForContinuityInPeriodicCurrent : 25\n";
		   continuityInfo.m_totalReadingContinuousRange ++;
		   continuityInfo.m_startIndexValueOfContinuousRange = startIndex;
		   continuityInfo.m_endIndexValueOfContinuousRange = periodicCurrentVector[index + 1];
	   }
	   else
	   {
		   ::std::cout<<"checkForContinuityInPeriodicCurrent : 32\n";
		   break;
	   }
   }
}

std::vector<ContinuityInfo> CalculateRangeAndReadings(std::vector<int> periodicCurrentVector)
{
    ::std::cout<<"CalculateRangeAndReadings : 40\n";
    int CurrentIndexInPeriodicCurrentVector = 0;
	std::vector<ContinuityInfo> continuityInfoList;
	std::sort(periodicCurrentVector.begin(), periodicCurrentVector.end());
    while(true == (CurrentIndexInPeriodicCurrentVector < periodicCurrentVector.size()))
	{
		    ::std::cout<<"CalculateRangeAndReadings : 46\n";
	   ContinuityInfo continuityInfo;
       checkForContinuityInPeriodicCurrent(periodicCurrentVector, CurrentIndexInPeriodicCurrentVector, continuityInfo);
	   if(continuityInfo.m_totalReadingContinuousRange > 1)
	   {
		       ::std::cout<<"CalculateRangeAndReadings : 51\n";
		  continuityInfoList.push_back(continuityInfo);
	      CurrentIndexInPeriodicCurrentVector = CurrentIndexInPeriodicCurrentVector + continuityInfo.m_totalReadingContinuousRange - 1;
	   }
	   CurrentIndexInPeriodicCurrentVector++;
	}
	return continuityInfoList;
}