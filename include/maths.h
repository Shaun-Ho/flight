#pragma once

double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);

class Vector {
public:
  float x;
  float y;
  float z;

  Vector(void);
  Vector(double xi, double yi, double zi);

  // operations
  Vector &operator+=(Vector u);

  // methods
  void normalise();
};

Vector operator*(Vector u, double m);
Vector operator*(double m, Vector u);

Vector operator/(Vector u, double m);
Vector operator/(double m, Vector u);