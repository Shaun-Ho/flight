#include <../include/aircraft.h>
#include <../include/aircraft_data.h>
#include <gtest/gtest.h>

TEST(AircraftTest, AircraftConstructor) {
  Aircraft my_aircraft;
  ASSERT_GT(my_aircraft.mass, 0.0);
}