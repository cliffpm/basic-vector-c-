// Cliff Pham
// CSE 

#include "Vector.h"

namespace vector0 {

// empty vector with 0's for all axis comp.
Vector::Vector() {
  v_ = new float[3];
  init(0, 0, 0);
}

// vector with declared axis comp.
Vector::Vector(const float x, const float y, const float z) {
  v_ = new float[3];
  init(x, y, z);
}

// copy constructor
Vector::Vector(const Vector &v) {
  v_ = new float[3];
  init(v.v_[0], v.v_[1], v.v_[2]);
}

// destructor deallocate vector
Vector::~Vector() {
  delete[] v_;
}

// assignment operator
Vector& Vector::operator=(const Vector &rhs) {
  if (this != &rhs) {
    init(rhs.v_[0], rhs.v_[1], rhs.v_[2]);
  }
  return *this;
}

// dot product returns scalar value
double operator*(const Vector &a, const Vector &b) {
  double value = 0.0;
  for (int i =0; i < 3; i++) {
    value += (a.v_[i] * b.v_[i]);
  }
  return value;
}

// scalar multiplication with vector k<x,y,z>
Vector operator*(const double k, const Vector &v) {
  Vector res;
  for (int i = 0; i < 3; i++) {
    res.v_[i] = (k*v.v_[i]);
  }
  return res;
}
// scalar multiplication: <x,y,z>k
Vector operator*(const Vector &v, const double k) {
  Vector res;
  for (int i = 0; i < 3; i++) {
    res.v_[i] = (k*v.v_[i]);
  }
  return res;
}

ostream& operator<<(ostream &out, const Vector &v) {
  out << "(" << v.v_[0] << "," << v.v_[1] << "," << v.v_[2] << ")";
  return out;
}

void Vector::init(const float x, const float y, const float z) {
  v_[0] = x;
  v_[1] = y;
  v_[2] = z;
}

}  // namespace vector0
