#include <../include/aircraft_data.h>
#include <gtest/gtest.h>
#include <iostream>

class AerofoilDataTest : public testing::TestWithParam<AircraftLiftingSurface> {
protected:
  AerofoilDataTest() {
    // Code here will be called before each test
  }

  virtual ~AerofoilDataTest() {
    // Code here will be called after each test
  }
};

TEST_P(AerofoilDataTest, AerofoilDataConstruction) {
  AerofoilPerformance data = read_lifting_surface_performance(GetParam());

  std::vector<double> expected_angles;
  std::string expected_name;
  int j{0};
  switch (GetParam()) {
  case OUTER_WING:
  case INNER_WING:
    for (double i = -10.0; i <= 20.0; i += 0.5) {
      expected_angles.push_back(i);
      j++;
    }
    expected_name = "NACA2406";
    break;

  case HORIZONTAL_STABILISER:
  case VERTICAL_STABILISER:
    expected_angles.push_back(-20);
    expected_angles.push_back(-18);
    expected_angles.push_back(-16);
    expected_angles.push_back(-14.5);
    for (double i = -13.5; i <= 13.5; i += 0.5) {
      expected_angles.push_back(i);
    }
    expected_angles.push_back(14.5);
    expected_angles.push_back(16);
    expected_angles.push_back(18);
    expected_angles.push_back(20);

    expected_name = "NACA0006";
    break;

  default:
    throw std::invalid_argument("Enum exhausted");
  }
  ASSERT_EQ(data.name, expected_name);
  ASSERT_EQ(data.angle_of_attacks, expected_angles);
};

INSTANTIATE_TEST_CASE_P(OuterWingTest, AerofoilDataTest,
                        testing::Values(AircraftLiftingSurface::OUTER_WING));

INSTANTIATE_TEST_CASE_P(InnerWingTest, AerofoilDataTest,
                        testing::Values(AircraftLiftingSurface::INNER_WING));

INSTANTIATE_TEST_CASE_P(
    HorizontalStabiliserTest, AerofoilDataTest,
    testing::Values(AircraftLiftingSurface::HORIZONTAL_STABILISER));

INSTANTIATE_TEST_CASE_P(
    VerticalStabiliserTest, AerofoilDataTest,
    testing::Values(AircraftLiftingSurface::VERTICAL_STABILISER));

class AerofoilPerformanceFixture : public ::testing::Test {
protected:
  AerofoilPerformance *outer_wing;
  AerofoilPerformance *inner_wing;
  AerofoilPerformance *horizontal_stabiliser;
  AerofoilPerformance *vertical_stabiliser;

  void SetUp() override {
    outer_wing = new AerofoilPerformance(
        read_lifting_surface_performance(AircraftLiftingSurface::OUTER_WING));
    inner_wing = new AerofoilPerformance(
        read_lifting_surface_performance(AircraftLiftingSurface::INNER_WING));
    horizontal_stabiliser =
        new AerofoilPerformance(read_lifting_surface_performance(
            AircraftLiftingSurface::HORIZONTAL_STABILISER));
    vertical_stabiliser =
        new AerofoilPerformance(read_lifting_surface_performance(
            AircraftLiftingSurface::VERTICAL_STABILISER));
  }
};

TEST_F(AerofoilPerformanceFixture, TestLiftInterpolation) {
  ASSERT_FLOAT_EQ(outer_wing->interpolate_lift(3.25), 0.6073);
  ASSERT_FLOAT_EQ(inner_wing->interpolate_lift(3.25), 0.6073);
  ASSERT_FLOAT_EQ(horizontal_stabiliser->interpolate_lift(3.25), 0.37065);
  ASSERT_FLOAT_EQ(vertical_stabiliser->interpolate_lift(3.25), 0.37065);
};

TEST_F(AerofoilPerformanceFixture, TestDragInterpolation) {
  ASSERT_FLOAT_EQ(outer_wing->interpolate_drag(3.25), 0.00310);
  ASSERT_FLOAT_EQ(inner_wing->interpolate_drag(3.25), 0.00310);
  ASSERT_FLOAT_EQ(horizontal_stabiliser->interpolate_drag(3.25), 0.002935);
  ASSERT_FLOAT_EQ(vertical_stabiliser->interpolate_drag(3.25), 0.002935);
};
