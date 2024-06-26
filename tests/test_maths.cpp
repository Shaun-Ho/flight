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

TEST(VectorOperations, VectorEquals) {
  Vector<double> vec_1 = Vector<double>(1.0, 2.0, 3.0);
  Vector<double> vec_2 = Vector<double>(1.0, 2.0, 3.0);
  ASSERT_TRUE(vec_1 == vec_2);
};

TEST(VectorOperations, VectorAdditionEqual) {
  Vector<double> vec_1 = Vector<double>(1.0, 2.0, 3.0);
  Vector<double> vec_2 = Vector<double>(1.0, 2.0, 3.0);
  vec_1 += vec_2;
  ASSERT_TRUE(vec_1 == Vector<double>(2.0, 4.0, 6.0));
};

TEST(VectorOperations, VectorAddition) {
  Vector<double> vec_1 = Vector<double>(2.0, 4.0, 6.0);
  Vector<double> vec_2 = Vector<double>(1.0, 2.0, 3.0);
  Vector<double> vec_3 = vec_1 + vec_2;
  ASSERT_TRUE(vec_3 == Vector<double>(3.0, 6.0, 9.0));
};

TEST(VectorOperations, VectorSubtraction) {
  Vector<double> vec_1 = Vector<double>(2.0, 4.0, 6.0);
  Vector<double> vec_2 = Vector<double>(1.0, 2.0, 3.0);
  Vector<double> vec_3 = vec_1 - vec_2;
  ASSERT_TRUE(vec_3 == Vector<double>(1.0, 2.0, 3.0));
};

TEST(VectorOperations, VectorMultiplyByDouble) {

  Vector<double> vec_1 = Vector<double>(1.0, 2.0, 3.0);
  double scalar{3.0};
  Vector<double> vec_2 = vec_1 * scalar;
  ASSERT_TRUE(vec_2 == Vector<double>(3.0, 6.0, 9.0));
}

TEST(VectorOperations, VectorDivideByDouble) {

  Vector<double> vec_1 = Vector<double>(1.0, 2.0, 4.0);
  double scalar{2.0};
  Vector<double> vec_2 = vec_1 / scalar;
  ASSERT_TRUE(vec_2 == Vector<double>(0.5, 1.0, 2.0));
}

TEST(VectorOperations, VectorNormalisation) {
  Vector<double> vec_1 = Vector<double>(0.0, 0.0, 2.0);
  vec_1.normalise();
  ASSERT_TRUE(vec_1 == Vector<double>(0.0, 0.0, 1.0));

  Vector<double> vec_2 = Vector<double>(0.0, 2.0, 0.0);
  vec_2.normalise();
  ASSERT_TRUE(vec_2 == Vector<double>(0.0, 1.0, 0.0));

  Vector<double> vec_3 = Vector<double>(2.0, 0.0, 0.0);
  vec_3.normalise();
  ASSERT_TRUE(vec_3 == Vector<double>(1.0, 0.0, 0.0));
};

TEST(MatrixOperations, MatrixInitialisation) {
  Matrix3x3<double> matrix(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
};

TEST(MatrixOperations, MatrixDivideByScalar) {
  Matrix3x3<double> matrix(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
  Matrix3x3<double> matrix2 = matrix / 2.0;
  Matrix3x3<double> matrix_expected(0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0,
                                    4.5);
  ASSERT_TRUE(matrix2 == matrix_expected);
};

TEST(MatrixOperations, MatrixGetElement) {
  Matrix3x3<double> matrix(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
  ASSERT_EQ(matrix[0][1], 2.0);
};

TEST(MatrixOperations, MatrixSetElement) {
  Matrix3x3<double> matrix;
  matrix[0][1] = 1.0;

  Matrix3x3<double> matrix_expected(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                    0.0);
  ASSERT_TRUE(matrix == matrix_expected);
};

TEST(MatrixOperations, MatrixInverse) {
  Matrix3x3<double> matrix(0.0, -3.0, -2.0, 1.0, -4.0, -2.0, -3.0, 4.0, 1.0);
  Matrix3x3<double> matrix_inversed = matrix.inverse();
  Matrix3x3<double> matrix_expected(4.0, -5.0, -2.0, 5.0, -6.0, -2.0, -8.0, 9.0,
                                    3.0);
  ASSERT_TRUE(matrix_inversed == matrix_expected);
};