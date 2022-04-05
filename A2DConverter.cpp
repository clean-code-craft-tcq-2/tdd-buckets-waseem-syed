#include "A2DConverter.h"
#include <math.h>

int getAmpsInDigital(int ampsInAnalog)
{
   return 3;
}

std::vector<int> ConvertAmpsListFromAToD(std::vector<int> AmpsInAnalog)
{
	std::vector<int> AmpsInDigital;
	std::vector<int>::iterator AnalogDataItr = AmpsInAnalog.begin();
	while(AnalogDataItr != AmpsInAnalog.end())
	{
		if(*AnalogDataItr > 1 && *AnalogDataItr <= 4094)
		{
			int AmpInDigital = getAmpsInDigital(*AnalogDataItr);
			AmpsInDigital.push_back(AmpInDigital);
		}
	}
	return AmpsInDigital;
}