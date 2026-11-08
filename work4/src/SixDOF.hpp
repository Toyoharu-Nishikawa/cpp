#pragma once

#include "vector.hpp"
#include "quaternion.hpp"
#include "rk4.hpp"

class SixDOF{
public:
  void advance();
  void setRK4(RK4<13>::DerivativeFunc dfdt);
  void* createOthers();

private:
  RK4<13> rk4;
  Vec3 r;
  Vec3 V;
  Quaternion q;
  Vec3 omega;
  double M;
  double t;
  double dt;
};

