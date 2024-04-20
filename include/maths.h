#pragma once
#include <array>

double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);

template <typename T> class Vector {
public:
  T x;
  T y;
  T z;

  Vector(void);
  Vector(T xi, T yi, T zi);

  Vector &operator+=(Vector u);

  void normalise();
};

template <typename T> Vector<T> operator+(Vector<T> u, Vector<T> v);

template <typename T> Vector<T> operator-(Vector<T> u, Vector<T> v);

template <typename T> Vector<T> operator*(Vector<T> u, T m);
template <typename T> Vector<T> operator*(T m, Vector<T> u);

Vector<double> operator/(Vector<double> u, double m);

template <typename T> class Matrix3x3 {

public:
  // double data[3][3];
  std::array<std::array<T, 3>, 3> data;

  Matrix3x3(void);
  // clang-format off
	Matrix3x3(
    T r1c1, T r1c2, T r1c3, 
		T r2c1, T r2c2, T r2c3,
    T r3c1, T r3c2, T r3c3
  );
  // clang-format on
  class Proxy {
  public:
    Proxy(std::array<T, 3> &_data);
    T &operator[](int index);

  private:
    std::array<T, 3> &_data;
  };

  Proxy operator[](int index);
  Matrix3x3<double> inverse();
  bool operator==(const Matrix3x3<T> &other) const;

private:
};

Matrix3x3<double> operator/(Matrix3x3<double> m, double s);