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

Vector operator+(Vector u, Vector v);

Vector operator-(Vector u, Vector v);

Vector operator*(Vector u, double m);
Vector operator*(double m, Vector u);

Vector operator/(Vector u, double m);
Vector operator/(double m, Vector u);

class Matrix3x3 {

public:
  double data[3][3];

  Matrix3x3(void);
  // clang-format off
	Matrix3x3(
    double r1c1, double r1c2, double r1c3, 
		double r2c1, double r2c2, double r2c3,
    double r3c1, double r3c2, double r3c3
  );
  // clang-format on
  class Proxy {
  public:
    Proxy(double *_data);
    double &operator[](int index);

  private:
    double *_data;
  };

  Proxy operator[](int index);
  Matrix3x3 inverse();

private:
  double determinant;
  void compute_and_set_determinant();
};

Matrix3x3 operator/(Matrix3x3 m, double s);