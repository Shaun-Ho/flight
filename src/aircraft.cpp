#include <../include/aircraft.h>
#include <../include/aircraft_data.h>
#include <iostream>

Aircraft::Aircraft(AircraftModel model = AircraftModel::AIRCRAFT_1) {
  // setting aircraft properties
  this->fill_aircraft_properties(model);
}

void Aircraft::fill_aircraft_properties(AircraftModel model_enum) {
  switch (model_enum) {
  case AIRCRAFT_2:
    break;

  default:
    this->body_elements[0] = Aircraft_1[0];
  }
}
Aircraft::~Aircraft() {}

void Aircraft::custom_print() {
  std::cout << this->body_elements[0].element_area << std::endl;
};
