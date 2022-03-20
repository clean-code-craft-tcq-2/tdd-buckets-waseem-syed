#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"

TEST_CASE("Test Smallest Range") 
{

  std::vector<int> periodicCurrentInput {1, 2, 4};
  int numberOfReadings = CalculateRangeAndReadings(periodicCurrentInput);

  assert(numberOfReadings == 2);
}