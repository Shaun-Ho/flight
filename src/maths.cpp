#include <../include/maths.h>
#include <iostream>
#include <math.h>

double degrees_to_radians(double degrees) { return degrees * M_PI / 180.0; }

double radians_to_degrees(double radians) { return radians * 180.0 / M_PI; };

template <> Vector<double>::Vector(void) {
  x = 0.0;
  y = 0.0;
  z = 0.0;
};

template <> Vector<int>::Vector(void) {
  x = 0;
  y = 0;
  z = 0;
};

template <typename T> Vector<T>::Vector(T xi, T yi, T zi) {
  x = xi;
  y = yi;
  z = zi;
};

template <typename T> Vector<T> &Vector<T>::operator+=(Vector u) {
  x += u.x;
  y += u.y;
  z += u.z;
  return *this;
}

template <typename T> bool Vector<T>::operator==(Vector u) {
  return (x == u.x) && (y == u.y) && (z == u.z);
}

template <typename T> Vector<T> operator+(Vector<T> u, Vector<T> v) {
  return Vector<T>(u.x + v.x, u.y + v.y, u.z + v.z);
}

template <typename T> Vector<T> operator-(Vector<T> u, Vector<T> v) {
  return Vector<T>(u.x - v.x, u.y - v.y, u.z - v.z);
}

template <typename T> Vector<T> operator*(Vector<T> u, T m) {
  return Vector<T>(u.x * m, u.y * m, u.z * m);
}

template <typename T> Vector<T> operator*(T m, Vector<T> u) {
  return Vector<T>(u.x * m, u.y * m, u.z * m);
}

Vector<double> operator/(Vector<double> u, double m) {
  return Vector<double>(u.x / m, u.y / m, u.z / m);
}
template <typename T> void Vector<T>::normalise() {
  double magnitude;
  magnitude = sqrt(x * x + y * y + z * z);
  x /= magnitude;
  y /= magnitude;
  z /= magnitude;
}

template class Vector<double>;
template class Vector<int>;
template Vector<double> operator+(Vector<double> u, Vector<double> v);
template Vector<double> operator-(Vector<double> u, Vector<double> v);
template Vector<double> operator*(Vector<double> u, double m);
template Vector<double> operator*(double m, Vector<double> u);

template <> Matrix3x3<double>::Matrix3x3(void) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      data[i][j] = 0.0;
    }
  }
};
template <> Matrix3x3<int>::Matrix3x3(void) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      data[i][j] = 0;
    }
  }
};
// clang-format off
template <typename T> Matrix3x3<T>::Matrix3x3(
  T r1c1, T r1c2, T r1c3, 
  T r2c1, T r2c2, T r2c3, 
  T r3c1, T r3c2, T r3c3
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

template <typename T>
Matrix3x3<T>::Proxy::Proxy(std::array<T, 3> &_data) : _data(_data) {}

template <typename T> T &Matrix3x3<T>::Proxy::operator[](int index) {
  return _data[index];
};

template <typename T>
typename Matrix3x3<T>::Proxy Matrix3x3<T>::operator[](int index) {
  return Proxy(data[index]);
};

template <typename T>
bool Matrix3x3<T>::operator==(const Matrix3x3<T> &other) const {
  return this->data == other.data;
};

template <typename T> Matrix3x3<double> Matrix3x3<T>::inverse() {

  double determinant =
      data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
      data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
      data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);

  determinant = (determinant == 0.0) ? 1.0 : determinant;

  return Matrix3x3<double>(
             (data[1][1] * data[2][2] - data[1][2] * data[2][1]),
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

Matrix3x3<double> operator/(Matrix3x3<double> m, double s) {
  return Matrix3x3<double>(m[0][0] / s, m[0][1] / s, m[0][2] / s, m[1][0] / s,
                           m[1][1] / s, m[1][2] / s, m[2][0] / s, m[2][1] / s,
                           m[2][2] / s);
};

template Matrix3x3<double> Matrix3x3<double>::inverse();
template bool
Matrix3x3<double>::operator==(const Matrix3x3<double> &other) const;