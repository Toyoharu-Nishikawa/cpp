#pragma once
#include "vector.hpp"
#include <stddef.h>


//typedef void (*DerivativeFunc)(double t, double dt, void* x, void* property);

//template<size_t N>
//Vec<N> rk4(double t, double dt, const Vec<N>& x, const void* property,
//          Vec<N>(*dfdt)(double,double,const Vec<N>&,const void*){
//  const Vec<N> k1 = dfdt(t     , dt, x                                , property);
//  const Vec<N> k2 = dfdt(t+dt/2, dt, addVec(x, mulScalarVec(dt/2, k1)), property);
//  const Vec<N> k3 = dfdt(t+dt/2, dt, addVec(x, mulScalarVec(dt/2, k2)), property);
//  const Vec<N> k4 = dfdt(t+dt  , dt, addVec(x, mulScalarVec(dt  , k3)), property);
//
//  const Vec<N> tmp1 = addVec(k1, mulScalarVec(2, k2));
//  const Vec<N> tmp2 = addVec(tmp1, mulScalarVec(2, k3));
//  const Vec<N> tmp3 = addVec(tmp2, k4);
//  const Vec<N> tmp4 = mulScalarVec(dt/6, tmp3);
//  const Vec<N> newState = addVec(x, tmp4);
//
//  return newState;
//}

template<size_t N>
class RK4{
public:
  typedef Vec<N> (*DerivativeFunc)(double, double,const Vec<N>&,const void*);
  void setDerivativeFunc(DerivativeFunc f){
    dfdt = f;
  }
  Vec<N> step(double t, double dt, const Vec<N>& x, const void* property){
    const Vec<N> k1 = dfdt(t     , dt, x                                , property);
    const Vec<N> k2 = dfdt(t+dt/2, dt, addVec(x, mulScalarVec(dt/2, k1)), property);
    const Vec<N> k3 = dfdt(t+dt/2, dt, addVec(x, mulScalarVec(dt/2, k2)), property);
    const Vec<N> k4 = dfdt(t+dt  , dt, addVec(x, mulScalarVec(dt  , k3)), property);

    const Vec<N> tmp1 = addVec(k1, mulScalarVec(2, k2));
    const Vec<N> tmp2 = addVec(tmp1, mulScalarVec(2, k3));
    const Vec<N> tmp3 = addVec(tmp2, k4);
    const Vec<N> tmp4 = mulScalarVec(dt/6, tmp3);
    const Vec<N> newState = addVec(x, tmp4);

    return newState;
  }
private:
  DerivativeFunc dfdt;
};
