#include <../include/maths.h>
#include <math.h>

double degrees_to_radians(double degrees) { return degrees * M_PI / 180.0; };

double radians_to_degrees(double radians) { return radians * 180.0 / M_PI; };

Vector::Vector(void) {
  x = 0.0;
  y = 0.0;
  z = 0.0;
};

Vector::Vector(double xi, double yi, double zi) {
  x = xi;
  y = yi;
  z = zi;
};
