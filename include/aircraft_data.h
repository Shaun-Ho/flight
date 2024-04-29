#pragma once
#include <maths.h>
#include <string>
#include <vector>

enum AircraftModel { AIRCRAFT_1, AIRCRAFT_2 };

typedef struct _BodyElement {
  double mass;
  Vector<double> coordinates_from_tail;
  Vector<double> local_inertia;
  double incidence_angle;
  double dihedral_angle;
  double element_area;
  double flap_incidence;
  Vector<double> center_of_gravity;
  Vector<double> normal_vector;

} BodyElement, *pBodyElement;

extern BodyElement Aircraft_1[8];

enum AircraftLiftingSurface {
  OUTER_WING,
  INNER_WING,
  HORIZONTAL_STABILISER,
  VERTICAL_STABILISER
};

class AerofoilPerformance {
private:
  int data_points;
  AircraftLiftingSurface lifting_surface;

public:
  std::string name;
  std::vector<double> angle_of_attacks;
  std::vector<double> lift_coefficients;
  std::vector<double> drag_coefficients;

  AerofoilPerformance(std::string aerofoil_name,
                      AircraftLiftingSurface lifting_surface,
                      std::vector<double> angle_of_attacks,
                      std::vector<double> lift_coefficients,
                      std::vector<double> drag_coefficients);
  AerofoilPerformance(std::string aerofoil_name,
                      AircraftLiftingSurface lifting_surface,
                      std::ifstream performance_file);
  double interpolate_lift(double angle_of_attack, double flap_angle = 0.0);
  double interpolate_drag(double angle_of_attack, double flap_angle = 0.0);
};
AerofoilPerformance
read_lifting_surface_performance(AircraftLiftingSurface lifting_surface);
