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
  double total_mass{0};
  for (int i{0}; i < 8; i++) {
    total_mass += this->body_elements[i].mass;
  }

  this->mass = total_mass;
  // Calculate normal vector of each body element
  for (int i{0}; i < 8; i++) {
    double incidence_radians =
        degrees_to_radians(this->body_elements[i].incidence_angle);
    double dihedral_radians =
        degrees_to_radians(this->body_elements[i].dihedral_angle);
    this->body_elements[i].normal_vector = Vector<double>(
        std::sin(incidence_radians),
        std::cos(incidence_radians) * std::sin(dihedral_radians),
        std::cos(incidence_radians) * std::sin(dihedral_radians));
    this->body_elements[i].normal_vector.normalise();
  }

  // calculating centre of gravity
  Vector<double> moment;
  for (int i{0}; i < 8; i++) {
    moment += this->body_elements[i].mass *
              this->body_elements[i].coordinates_from_tail;
  }

  this->center_of_gravity = moment / total_mass;

  // calculate moment of inertia
  for (int i = 0; i < 8; i++) {
    this->body_elements[i].center_of_gravity =
        this->body_elements[i].coordinates_from_tail - center_of_gravity;
  }
  double Ixx{0};
  double Iyy{0};
  double Izz{0};
  double Ixy{0};
  double Ixz{0};
  double Iyz{0};

  for (int i = 0; i < 8; i++) {
    Ixx += this->body_elements[i].local_inertia.x +
           this->body_elements[i].mass *
               (this->body_elements[i].center_of_gravity.y *
                    this->body_elements[i].center_of_gravity.y +
                this->body_elements[i].center_of_gravity.z *
                    this->body_elements[i].center_of_gravity.z);
    Iyy += this->body_elements[i].local_inertia.y +
           this->body_elements[i].mass *
               (this->body_elements[i].center_of_gravity.z *
                    this->body_elements[i].center_of_gravity.z +
                this->body_elements[i].center_of_gravity.x *
                    this->body_elements[i].center_of_gravity.x);
    Izz += this->body_elements[i].local_inertia.z +
           this->body_elements[i].mass *
               (this->body_elements[i].center_of_gravity.x *
                    this->body_elements[i].center_of_gravity.x +
                this->body_elements[i].center_of_gravity.y *
                    this->body_elements[i].center_of_gravity.y);
    Ixy += this->body_elements[i].mass *
           (this->body_elements[i].center_of_gravity.x *
            this->body_elements[i].center_of_gravity.y);
    Ixz += this->body_elements[i].mass *
           (this->body_elements[i].center_of_gravity.x *
            this->body_elements[i].center_of_gravity.z);
    Iyz += this->body_elements[i].mass *
           (this->body_elements[i].center_of_gravity.y *
            this->body_elements[i].center_of_gravity.z);
  }

  // clang-format off
  Matrix3x3 moment_of_inertia(
     Ixx, -Ixy, -Ixz,
    -Ixy,  Iyy, -Iyz,
    -Ixz, -Iyz,  Izz
  );
  // clang-format on

  this->moment_of_inertia = moment_of_inertia;
  this->moment_of_inertia_inverse = moment_of_inertia.inverse();
};

void Aircraft::custom_print() {
  std::cout << this->body_elements[0].element_area << std::endl;
};
