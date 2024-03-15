#include <../include/aircraft.h>
#include <../include/aircraft_data.h>
#include <iostream>

Aircraft::Aircraft(AircraftModel model) {
  // setting aircraft properties
  this->fill_aircraft_properties(model);
  this->calculate_aircraft_mass_properties();
}

void Aircraft::fill_aircraft_properties(AircraftModel model_enum) {
  switch (model_enum) {

  default:
    for (int i{0}; i < 8; i++) {
      this->body_elements[i] = Aircraft_1[i];
    }
  }
}
Aircraft::~Aircraft() {}

void Aircraft::calculate_aircraft_mass_properties() {
  double mass{0};
  for (int i{0}; i < 8; i++) {
    mass += this->body_elements[i].mass;
  }
  this->mass = mass;
}

void Aircraft::custom_print() {
  std::cout << this->body_elements[0].element_area << std::endl;
};
