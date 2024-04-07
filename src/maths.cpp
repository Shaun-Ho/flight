#include <../include/maths.h>
#include <math.h>
#include <iostream>

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

Vector operator+(Vector u, Vector v) {
  return Vector(u.x + v.x, u.y + v.y, u.z + v.z);
}
Vector operator-(Vector u, Vector v) {
  return Vector(u.x - v.x, u.y - v.y, u.z - v.z);
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
  x /= magnitude;
  y /= magnitude;
  z /= magnitude;
}

Matrix3x3::Matrix3x3(void) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      data[i][j] = 0.0;
    }
  }
};
// clang-format off
Matrix3x3::Matrix3x3(
  double r1c1, double r1c2, double r1c3, 
  double r2c1, double r2c2, double r2c3, 
  double r3c1, double r3c2, double r3c3
                      // clang-format on
) {
  data[0][0] = r1c1;
  data[0][1] = r1c2;
  data[0][2] = r1c3;
  data[1][0] = r2c1;
  data[1][1] = r2c2;
  data[1][2] = r2c3;
  data[2][0] = r3c1;
  data[2][1] = r3c2;
  data[2][2] = r3c3;
};

Matrix3x3::Proxy::Proxy(double *_data) : _data(_data) {}

double &Matrix3x3::Proxy::operator[](int index) { return _data[index]; };

Matrix3x3::Proxy Matrix3x3::operator[](int index) {
  return Proxy(data[index]);
};

bool Matrix3x3::operator==(const Matrix3x3 &other) const {
  return this->data == other.data;
};

Matrix3x3 Matrix3x3::inverse() {

  double determinant =
      data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
      data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
      data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);

  determinant = (determinant == 0.0) ? 1.0 : determinant;

  return Matrix3x3((data[1][1] * data[2][2] - data[1][2] * data[2][1]),
                   -(data[0][1] * data[2][2] - data[0][2] * data[2][1]),
                   (data[0][1] * data[1][2] - data[0][2] * data[1][1]),
                   -(data[1][0] * data[2][2] - data[1][2] * data[2][0]),
                   (data[0][0] * data[2][2] - data[0][2] * data[2][0]),
                   -(data[0][0] * data[1][2] - data[0][2] * data[1][0]),
                   (data[1][0] * data[2][1] - data[1][1] * data[2][0]),
                   -(data[0][0] * data[2][1] - data[0][1] * data[2][0]),
                   (data[0][0] * data[1][1] - data[0][1] * data[1][0])) /
         determinant;
};

Matrix3x3 operator/(Matrix3x3 m, double s) {
  return Matrix3x3(m[0][0] / s, m[0][1] / s, m[0][2] / s, m[1][0] / s,
                   m[1][1] / s, m[1][2] / s, m[2][0] / s, m[2][1] / s,
                   m[2][2] / s);
};