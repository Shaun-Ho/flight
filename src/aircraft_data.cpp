#include <../include/aircraft_data.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

BodyElement Aircraft_1[8] = {
    {6.56, Vector<double>(14.5, 12.0, 2.5), Vector<double>(13.92, 10.50, 24.00),
     -3.5, 0.0, 31.2, 0.0, Vector<double>(0.0, 0.0, 0.0),
     Vector<double>(0.0, 0.0, 0.0)},
    {7.31, Vector<double>(14.5, 5.5, 2.5), Vector<double>(21.95, 12.22, 33.67),
     -3.5, 0.0, 36.4, 0.0, Vector<double>(0.0, 0.0, 0.0),
     Vector<double>(0.0, 0.0, 0.0)},
    {7.31, Vector<double>(14.5, -5.5, 2.5), Vector<double>(21.95, 12.22, 33.67),
     -3.5, 0.0, 36.4, 0.0, Vector<double>(0.0, 0.0, 0.0),
     Vector<double>(0.0, 0.0, 0.0)},
    {6.56, Vector<double>(14.5, -12.0, 2.5),
     Vector<double>(13.92, 10.50, 24.00), -3.5, 0.0, 31.2, 0.0,
     Vector<double>(0.0, 0.0, 0.0), Vector<double>(0.0, 0.0, 0.0)},
    {2.62, Vector<double>(3.03, 2.5, 3.0), Vector<double>(0.837, 0.385, 1.206),
     0.0, 0.0, 10.8, 0.0},
    {2.62, Vector<double>(3.03, -2.5, 3.0), Vector<double>(0.837, 0.385, 1.206),
     0.0, 0.0, 10.8, 0.0},
    {2.93, Vector<double>(2.25, 0.0, 5.0), Vector<double>(1.262, 1.942, 0.718),
     0.0, 90.0, 12.0, 0.0, Vector<double>(0.0, 0.0, 0.0),
     Vector<double>(0.0, 0.0, 0.0)},
    {31.8, Vector<double>(15.25, 0.0, 1.5), Vector<double>(66.30, 861.9, 861.9),
     0.0, 0.0, 84.0, 0.0, Vector<double>(0.0, 0.0, 0.0),
     Vector<double>(0.0, 0.0, 0.0)}};

AerofoilPerformance::AerofoilPerformance(
    std::string aerofoil_name, AircraftLiftingSurface lifting_surface,
    std::vector<double> angle_of_attack_array,
    std::vector<double> lift_coefficients_array,
    std::vector<double> drag_coefficients_array) {
  name = aerofoil_name;
  angle_of_attacks = angle_of_attack_array;
  lift_coefficients = lift_coefficients_array;
  drag_coefficients = drag_coefficients_array;
  this->lifting_surface = lifting_surface;
}

AerofoilPerformance::AerofoilPerformance(std::string aerofoil_name,
                                         AircraftLiftingSurface lifting_surface,
                                         std::ifstream file) {
  name = aerofoil_name;
  this->lifting_surface = lifting_surface;
  int max_size{100};
  data_points = 0;
  std::string line;

  // skipping headers
  std::getline(file, line);

  // saving data
  while (std::getline(file, line) && data_points < max_size) {
    std::istringstream iss(line);
    double angle;
    double lift;
    double drag;
    char comma;
    if (!(iss >> angle >> comma >> lift >> comma >> drag)) {
      std::cerr << "Error reading line" << std::endl;
    }
    angle_of_attacks.push_back(angle);
    lift_coefficients.push_back(lift);
    drag_coefficients.push_back(drag);
    data_points++;
  }
}

AerofoilPerformance
read_lifting_surface_performance(AircraftLiftingSurface lifting_surface) {
  fs::path project_root = "./..";
  fs::path data_path = project_root / "data";
  std::string aerofoil_name;

  switch (lifting_surface) {
  case OUTER_WING: {
    aerofoil_name = "NACA2406";
    break;
  }
  case INNER_WING: {
    aerofoil_name = "NACA2406";
    break;
  }
  case HORIZONTAL_STABILISER: {
    aerofoil_name = "NACA0006";
    break;
  }
  case VERTICAL_STABILISER: {
    aerofoil_name = "NACA0006";
    break;
  }
  default:
    throw std::invalid_argument("Enum exhausted");
  }
  std::string file_name = (aerofoil_name + "_performance.csv");
  std::ifstream data_file(data_path / file_name);
  if (!data_file.is_open()) {
    std::cerr << "Error: unable to open file: " << file_name << std::endl;
  }
  return AerofoilPerformance(aerofoil_name, lifting_surface,
                              std::move(data_file));
};

double AerofoilPerformance::interpolate_lift(double angle_of_attack,
                                             double flap_angle) {
  double lift;
  for (int i = 0; i < data_points; i++) {
    if ((angle_of_attacks[i] <= angle_of_attack) &&
        (angle_of_attacks[i + 1] > angle_of_attack)) {
      lift = lift_coefficients[i] -
             (angle_of_attacks[i] - angle_of_attack) *
                 (lift_coefficients[i] - lift_coefficients[i + 1]) /
                 (angle_of_attacks[i] - angle_of_attacks[i + 1]);
      break;
    }
  }
  return lift;
};

double AerofoilPerformance::interpolate_drag(double angle_of_attack,
                                             double flap_angle) {
  double drag;
  for (int i = 0; i < data_points; i++) {
    if ((angle_of_attacks[i] <= angle_of_attack) &&
        (angle_of_attacks[i + 1] > angle_of_attack)) {
      drag = drag_coefficients[i] -
             (angle_of_attacks[i] - angle_of_attack) *
                 (drag_coefficients[i] - drag_coefficients[i + 1]) /
                 (angle_of_attacks[i] - angle_of_attacks[i + 1]);
      break;
    }
  }
  return drag;
};