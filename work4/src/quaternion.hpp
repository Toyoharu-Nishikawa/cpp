#pragma once

#include "vector.hpp"

#include <cmath>

struct Quaternion{
  double d[4];
};

Quaternion createQuaternionFromVector(const Vec3& v, double theta){
  Quaternion q={0};
  q.d[0] = v.d[0]*std::sin(theta/2);  
  q.d[1] = v.d[1]*std::sin(theta/2);  
  q.d[2] = v.d[2]*std::sin(theta/2);  
  q.d[3] = std::cos(theta/2);  
  return q;
}
