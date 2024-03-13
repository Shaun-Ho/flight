#include <../include/aircraft.h>
#include <../include/aircraft_data.h>
#include <../include/maths.h>
#include <iostream>

int main() {
  populate_aircraft();
  Aircraft myaircraft = Aircraft(AircraftModel::AIRCRAFT_1);
  myaircraft.custom_print();
  std::cout << "Hello World" << std::endl;
  return 0;
}