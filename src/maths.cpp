#include "maths.h"
#include <../include/maths.h>
#include <iostream>
#include <math.h>

double degrees_to_radians(double degrees) { return degrees * M_PI / 180.0; }

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

Vector &Vector::operator+=(Vector u) {
  x += u.x;
  y += u.y;
  z += u.z;
  return *this;
}
Vector operator*(Vector u, double m) {
  return Vector(u.x * m, u.y * m, u.z * m);
}
Vector operator*(double m, Vector u) {
  return Vector(u.x * m, u.y * m, u.z * m);
}
Vector operator/(Vector u, double m) {
  return Vector(u.x / m, u.y / m, u.z / m);
}
Vector operator/(double m, Vector u) {
  return Vector(u.x / m, u.y / m, u.z / m);
}

void Vector::normalise() {
  double magnitude;
  magnitude = sqrt(x * x + y * y + z * z);
  std::cout << magnitude << std::endl;
  x /= magnitude;
  y /= magnitude;
  z /= magnitude;
}
