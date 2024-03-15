#pragma once
#include <aircraft_data.h>
#include <maths.h>

class Aircraft {
private:
  BodyElement body_elements[8];
  Vector angular_velocity;
  Vector body_velocity;
  Vector moment;
  Vector Forces;

  void fill_aircraft_properties(AircraftModel model_enum);

public:
  AircraftModel aircraft_model;
  double mass;
  double thrust_setting;
  Vector position;
  Vector velocity;

  Aircraft(AircraftModel model = AircraftModel::AIRCRAFT_1);
  ~Aircraft();
  void custom_print();
};
