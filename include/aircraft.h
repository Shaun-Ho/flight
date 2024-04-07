#pragma once
#include <aircraft_data.h>
#include <maths.h>

class Aircraft {
private:
  BodyElement body_elements[8];
  Matrix3x3 moment_of_inertia;
  Matrix3x3 moment_of_inertia_inverse;
  Vector angular_velocity;
  Vector body_velocity;
  Vector moment;
  Vector Forces;

  void fill_aircraft_properties(AircraftModel model_enum);
  void calculate_aircraft_mass_properties();

public:
  AircraftModel aircraft_model;
  double mass;
  double thrust_setting;
  Vector center_of_gravity;
  Vector position;
  Vector velocity;

  Aircraft(AircraftModel model = AircraftModel::AIRCRAFT_1);
  ~Aircraft();
  void custom_print();
};
