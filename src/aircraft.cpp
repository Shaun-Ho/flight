#include <../include/aircraft.h>
#include <../include/aircraft_data.h>
#include <iostream>

Aircraft::Aircraft(AircraftModel model) {
  // setting aircraft properties
  this->fill_aircraft_properties(model);
}

void Aircraft::fill_aircraft_properties(AircraftModel model_enum) {
  switch (model_enum) {

  default:
    this->aircraft_model = model_enum;
    for (int i; i<8; i++){
      this->body_elements[i] = Aircraft_1[i];
    }
  }
}
Aircraft::~Aircraft() {}

void Aircraft::custom_print() {
  std::cout << this->body_elements[0].element_area << std::endl;
};
