#pragma once


#include <cmath>
#include <cstddef>

template<size_t N>
struct Vec{
  double d[N];
};

typedef Vec<3> Vec3;
typedef Vec<13> Vec13;

template<size_t N>
Vec<N> copyVec(Vec<N> vec){
  Vec<N> newVec={0};
  for(int i;i<N;i++){
    newVec.d[i] = vec.d[i];
  }
  return newVec;
}

template<size_t N>
Vec<N> mulScalarVec(const double a, const Vec<N>& vec){
  Vec<N> newVec={0};
  for(int i=0;i<N;i++){
    newVec.d[i] = a*vec.d[0];
  }
  return newVec;
}

template<size_t N>
Vec<N> addVec(const Vec<N>& vec_1, const Vec<N>& vec_2){
  Vec<N> newVec={0};
  for(int i=0;i<N;i++){
    newVec.d[i] = vec_1.d[i] + vec_2.d[i];
  }
  return newVec;
}

template<size_t N>
Vec<N> subVec(const Vec<N>& vec_1, const Vec<N>& vec_2){
  Vec<N> newVec={0};
  for(int i=0;i<N;i++){
    newVec.d[i] = vec_1.d[i] - vec_2.d[i];
  }
  return newVec;
}


template<size_t N>
double dotVec(const Vec<N>& vec_1, const Vec<N>& vec_2){
  double v = 0;
  for(int i=0;i<N;i++){
    v += vec_1.d[i] * vec_2.d[i];
  }
  return v;
}

Vec3 crossVec(const Vec3& vec_1, const Vec3& vec_2){
  Vec3 newVec={0};
  newVec.d[0] = vec_1.d[1]*vec_2.d[2] - vec_1.d[2]*vec_2.d[1];
  newVec.d[1] = vec_1.d[2]*vec_2.d[0] - vec_1.d[0]*vec_2.d[2];
  newVec.d[2] = vec_1.d[0]*vec_2.d[1] - vec_1.d[1]*vec_2.d[0];

  return newVec;
}

template<size_t N>
double absVec(const Vec<N>& vec){
  double v = 0;
  for(int i=0;i<N;i++){
    v += vec.d[i]*vec.d[i] ;
  }
  v = std::sqrt(v);
  return v;
}

template<size_t N>
Vec<N> normalizeVec(const Vec<N>& vec){
  double abs = absVec(vec);
  Vec<N> newVec={0};
  if(fabs(abs)<1e-9){
    return newVec;
  }
  else{
    for(int i=0;i<N;i++){
      newVec.d[i] = vec.d[i] / abs;
    }
    return newVec;
  }
}

