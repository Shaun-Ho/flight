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

TEST(VectorOperations, VectorAddition) {
  Vector vec_1 = Vector(1.0, 2.0, 3.0);
  Vector vec_2 = Vector(1.0, 2.0, 3.0);
  vec_1 += vec_2;
  ASSERT_EQ(vec_1.x, 2.0);
  ASSERT_EQ(vec_1.y, 4.0);
  ASSERT_EQ(vec_1.z, 6.0);
};

TEST(VectorOperations, VectorMultiplyByDouble) {

  Vector vec_1 = Vector(1.0, 2.0, 3.0);
  double scalar{3.0};
  Vector vec_2 = vec_1 * scalar;
  ASSERT_EQ(vec_2.x, 3.0);
  ASSERT_EQ(vec_2.y, 6.0);
  ASSERT_EQ(vec_2.z, 9.0);
}

TEST(VectorOperations, VectorDivideByDouble) {

  Vector vec_1 = Vector(1.0, 2.0, 4.0);
  double scalar{2.0};
  Vector vec_2 = vec_1 / scalar;
  ASSERT_EQ(vec_2.x, 0.5);
  ASSERT_EQ(vec_2.y, 1.0);
  ASSERT_EQ(vec_2.z, 2.0);
}

TEST(VectorOperations, VectorNormalisation) {
  Vector vec_1 = Vector(0.0, 0.0, 2.0);
  vec_1.normalise();
  ASSERT_EQ(vec_1.x, 0.0);
  ASSERT_EQ(vec_1.y, 0.0);
  ASSERT_EQ(vec_1.z, 1.0);

  Vector vec_2 = Vector(0.0, 2.0, 0.0);
  vec_2.normalise();
  ASSERT_EQ(vec_2.x, 0.0);
  ASSERT_EQ(vec_2.y, 1.0);
  ASSERT_EQ(vec_2.z, 0.0);

  Vector vec_3 = Vector(2.0, 0.0, 0.0);
  vec_3.normalise();
  ASSERT_EQ(vec_3.x, 1.0);
  ASSERT_EQ(vec_3.y, 0.0);
  ASSERT_EQ(vec_3.z, 0.0);
}