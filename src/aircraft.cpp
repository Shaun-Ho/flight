#include <../include/aircraft.h>
#include <../include/aircraft_data.h>
#include <iostream>
#include <math.h>

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
  // Calculating mass of aircraft
  double mass{0};
  for (int i{0}; i < 8; i++) {
    mass += this->body_elements[i].mass;
  }
  this->mass = mass;

  // Calculate normal vector of each body element
  for (int i{0}; i < 8; i++) {
    double incidence_radians =
        degrees_to_radians(this->body_elements[i].incidence_angle);
    double dihedral_radians =
        degrees_to_radians(this->body_elements[i].dihedral_angle);
    this->body_elements[i].normal_vector =
        Vector(std::sin(incidence_radians),
               std::cos(incidence_radians) * std::sin(dihedral_radians),
               std::cos(incidence_radians) * std::sin(dihedral_radians));
    this->body_elements[i].normal_vector.normalise();
  }

  // calculating centre of gravity
  Vector moment;
  for (int i{0}; i < 8; i++) {
    moment += this->body_elements[i].mass *
              this->body_elements[i].coordinates_from_tail;
  }

  this->center_of_gravity = moment / mass;
}

void Aircraft::custom_print() {
  std::cout << this->body_elements[0].element_area << std::endl;
};
