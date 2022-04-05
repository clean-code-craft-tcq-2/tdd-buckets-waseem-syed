#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "A2DConverter.h"

TEST_CASE("Test ConvertAmpsListFromAToD") 
{
   std::vector<int> ampsInAnalog {4094, 4000};
   std::vector<int> ampsInDigital = ConvertAmpsListFromAToD(ampsInAnalog);
   assert(flase == ampsInDigital.empty());

}