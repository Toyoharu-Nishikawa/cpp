#include "simulator.hpp"

void Simulator::update(){
  vehicle_.update(time_, dt_);
}

void Simulator::run(){
  while(time_<max_time_){
    vehicle_.update(time_, dt_);
    time_ += dt_;
  }
}
