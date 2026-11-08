#include "../src/vector.hpp"
#include "../src/rk4.hpp"

#include <iostream>
#include <cmath>

Vec<1> dfdt(double t, double dt, const Vec<1>& state, const void*  oth){
  const Vec<1> newX = {std::cos(t)};
  return newX;
} 


struct Property{ 
  double dt; 
  Vec<1> vec;
};



class One {
public:
  One(double globalTime=0, double localTime=0)
    :t(globalTime),s(localTime){
  }
  void initialize(const Property* property){
    dt = property->dt;
  }
  void setDerivativeFunc(RK4<1>::DerivativeFunc f){
    rk4.setDerivativeFunc(f);
  }
  void advance(){
    Vec<1> state = {vec.d[0]};
    Vec<1> newState = rk4.step(s, dt, state, oth);
    vec.d[0] = newState.d[0];
    s += dt;
  }
  void setGlobalTime(double globalTime){
    t = globalTime; 
  }
  Vec<1> getVec()const {return vec;}

private:
   RK4<1> rk4;
   Vec<1> vec;
   double t;
   double s;
   double dt;
   void* state;
   void* oth;
};

int main(){
  const Vec3 r1 = {1,2,3};
  const Vec3 r2 = {1,2,3};

  const Vec3 r3 = addVec(r1, r2);

  std::cout << "r3[0]=" <<r3.d[0]<< "\n";
  std::cout << "r3[1]=" <<r3.d[1]<< "\n";
  std::cout << "r3[2]=" <<r3.d[2]<< "\n";

  /* RK4 simulation */
  double t = 0; 
  const double dt = 0.1;
  Vec<1> vec = {0.0};
  int N = 100;

  const Property property = {dt, vec}; 

  One one;
  one.initialize(&property);
  one.setDerivativeFunc(dfdt);

  int j=0;
  for(int i=0;i<N;i++){
    j++;
    one.advance(); 
    std::cout << "j=" <<j <<";" ;
    std::cout << "sint=" << std::sin(j*dt) <<";" ;
    std::cout << "vec.d[0]=" <<one.getVec().d[0]<< "\n";
    t += dt;
    one.setGlobalTime(t);
  }

  return 0; 
}

