#pragma once
#include <aircraft_data.h>
#include <maths.h>

class Aircraft {
private:
  BodyElement body_elements[8];
  Matrix3x3<double> moment_of_inertia;
  Matrix3x3<double> moment_of_inertia_inverse;
  Vector<double> angular_velocity;
  Vector<double> body_velocity;
  Vector<double> moment;
  Vector<double> Forces;

  void fill_aircraft_properties(AircraftModel model_enum);
  void calculate_aircraft_mass_properties();

public:
  AircraftModel aircraft_model;
  double mass;
  double thrust_setting;
  Vector<double> center_of_gravity;
  Vector<double> position;
  Vector<double> velocity;

  Aircraft(AircraftModel model = AircraftModel::AIRCRAFT_1);
  ~Aircraft();
  void custom_print();
};
