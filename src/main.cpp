#include <../include/aircraft.h>
#include <../include/aircraft_data.h>
#include <../include/maths.h>
#include <iostream>

int main() {
  Aircraft myaircraft = Aircraft(AircraftModel::AIRCRAFT_1);
  std::cout << myaircraft.mass << std::endl;
  std::cout << "End of file" << std::endl;
  return 0;
}