#include "rk4.hpp"
#include "vector.hpp"
#include "quaternion.hpp"
#include "SixDOF.hpp"


double CL(double absV, double alpha){
  return 1;
}
double CD(double absV, double alpha){
  return 0.05;
}
double CY(double absV, double beta){
  return 0.05;
}


//Vec13 dfdt(double t, double dt, Vec13* state, void*  oth){
//  Vec3 r = {state.d[0], state.d[1],state.d[2]};
//  Vec3 V = {state.d[3], state.d[4],state.d[5]};
//  Quaternion q = {state.d[6], state.d[7],state.d[8],state.d[9]};
//  Vec3 omega = {state.d[10], state.d[11],state.d[12]};
//
//
//  const double absV = absVec(V);
//  double rho = oth->rho;
//  double S = oth->S;
//  Vec3 drdt = copyVec(V);
//  Vec3 dVdt = {0.5*rho*S*absV*oth->CL(v, 0), 0.5*rho*S*absV*oth->CD(v, 0),0.5*rho*S*absV*oth->CY(v, 0)};
//  Quaternion dqdt = {1,1,1,1};
//  Vec3 domegadt = {0, 0, 0};
//
//  Vec13 newState = {{
//    drd.dt[0], drd.dt[1], drd.dt[2],
//    dVd.dt[0], dVd.dt[1], dVd.dt[2],
//    dqd.dt[0], dqd.dt[1], dqd.dt[2], dqd.dt[3],
//    domegad.dt[0], domegad.dt[1], domegad.dt[2],
//  }};
//
//  return newState;
//}



//void SixDOF::setDeriveFunc(void* f){
//  dfdt = f
//}

//void SixDOF::create(void* f){
//  dfdt = f
//}

void SixDOF::setRK4(RK4<13>::DerivativeFunc dfdt){
  rk4.setDerivativeFunc(dfdt);
}

void SixDOF::advance(){
  Vec<13> state = {
    r.d[0], r.d[1],r.d[2],
    V.d[0], V.d[1],V.d[2],
    q.d[0], q.d[1],q.d[2],q.d[3],
    omega.d[0], omega.d[1],omega.d[2]
  };

  Vec<1> oth = {0}; 
  
  Vec<13> newState = rk4.step(t, dt, state, &oth);
  r.d[0]     = newState.d[0];
  r.d[1]     = newState.d[1]; 
  r.d[2]     = newState.d[2];

  V.d[0]     = newState.d[3];
  V.d[1]     = newState.d[4];
  V.d[2]     = newState.d[5];

  q.d[0]     = newState.d[6];
  q.d[1]     = newState.d[7];
  q.d[2]     = newState.d[8];
  q.d[3]     = newState.d[9];

  omega.d[0] = newState.d[10];
  omega.d[1] = newState.d[11];
  omega.d[2] = newState.d[12];
}

