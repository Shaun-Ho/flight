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

TEST(VectorOperations, VectorAdditionEqual) {
  Vector vec_1 = Vector(1.0, 2.0, 3.0);
  Vector vec_2 = Vector(1.0, 2.0, 3.0);
  vec_1 += vec_2;
  ASSERT_EQ(vec_1.x, 2.0);
  ASSERT_EQ(vec_1.y, 4.0);
  ASSERT_EQ(vec_1.z, 6.0);
};

TEST(VectorOperations, VectorAddition) {
  Vector vec_1 = Vector(2.0, 4.0, 6.0);
  Vector vec_2 = Vector(1.0, 2.0, 3.0);
  Vector vec_3 = vec_1 + vec_2;
  ASSERT_EQ(vec_3.x, 3.0);
  ASSERT_EQ(vec_3.y, 6.0);
  ASSERT_EQ(vec_3.z, 9.0);
};

TEST(VectorOperations, VectorSubtraction) {
  Vector vec_1 = Vector(2.0, 4.0, 6.0);
  Vector vec_2 = Vector(1.0, 2.0, 3.0);
  Vector vec_3 = vec_1 - vec_2;
  ASSERT_EQ(vec_3.x, 1.0);
  ASSERT_EQ(vec_3.y, 2.0);
  ASSERT_EQ(vec_3.z, 3.0);
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

TEST(MatrixOperations, MatrixInitialisation) {
  Matrix3x3 matrix(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
};

TEST(MatrixOperations, MatrixDivideByScalar) {
  Matrix3x3 matrix(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
  Matrix3x3 matrix2 = matrix / 2.0;
  ASSERT_EQ(matrix2[0][0], 0.5);
  ASSERT_EQ(matrix2[0][1], 1.0);
  ASSERT_EQ(matrix2[0][2], 1.5);
  ASSERT_EQ(matrix2[1][0], 2.0);
  ASSERT_EQ(matrix2[1][1], 2.5);
  ASSERT_EQ(matrix2[1][2], 3.0);
  ASSERT_EQ(matrix2[2][0], 3.5);
  ASSERT_EQ(matrix2[2][1], 4.0);
  ASSERT_EQ(matrix2[2][2], 4.5);
};

TEST(MatrixOperations, MatrixGetElement) {
  Matrix3x3 matrix(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
  ASSERT_EQ(matrix[0][1], 2.0);
};

TEST(MatrixOperations, MatrixSetElement) {
  Matrix3x3 matrix;
  matrix[0][1] = 1.0;

  ASSERT_EQ(matrix[0][0], 0.0);
  ASSERT_EQ(matrix[0][1], 1.0);
  ASSERT_EQ(matrix[0][2], 0.0);
  ASSERT_EQ(matrix[1][0], 0.0);
  ASSERT_EQ(matrix[1][1], 0.0);
  ASSERT_EQ(matrix[1][2], 0.0);
  ASSERT_EQ(matrix[2][0], 0.0);
  ASSERT_EQ(matrix[2][1], 0.0);
  ASSERT_EQ(matrix[2][2], 0.0);
};

TEST(MatrixOperations, MatrixInverse) {
  Matrix3x3 matrix(0.0, -3.0, -2.0, 1.0, -4.0, -2.0, -3.0, 4.0, 1.0);
  Matrix3x3 matrix_inversed = matrix.inverse();
  // Matrix3x3 matrix_expected(4.0, -5.0, -2.0, 5.0, -6.0, -2.0, -8.0, 9.0, 3.0);
  // ASSERT_TRUE(matrix_inversed == matrix_expected);
// };
  ASSERT_EQ(matrix_inversed[0][0], 4.0);
  ASSERT_EQ(matrix_inversed[0][1], -5.0);
  ASSERT_EQ(matrix_inversed[0][2], -2.0);
  ASSERT_EQ(matrix_inversed[1][0], 5.0);
  ASSERT_EQ(matrix_inversed[1][1], -6.0);
  ASSERT_EQ(matrix_inversed[1][2], -2.0);
  ASSERT_EQ(matrix_inversed[2][0], -8.0);
  ASSERT_EQ(matrix_inversed[2][1], 9.0);
  ASSERT_EQ(matrix_inversed[2][2], 3.0);
};