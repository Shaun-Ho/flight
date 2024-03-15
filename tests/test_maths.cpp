#include <../include/maths.h>
#include <gtest/gtest.h>
#include <math.h>

TEST(ConversionFunctions, DegreesToRadians) {
  double radians = degrees_to_radians(360);
  ASSERT_EQ(radians, 2 * M_PI);
};

TEST(ConversionFunctions, RadiansToDegrees) {
  double degrees = radians_to_degrees(M_PI);
  ASSERT_EQ(degrees, 180);
};