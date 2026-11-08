#pragma once

#include "vehicle.hpp"
#include "input.hpp"

#include <memory>

class Simulator{
  public:
    void loadInput(const Input input){
      max_time_ = input.max_time;
      dt_       = input.dt;
      vehicle_.setInitialState(input.vehicle_state);
    }
    void run();
    const VehicleState& getResult() const{
      return vehicle_.getState();
    }
  
  private:
    double time_{0.0};
    double max_time_{3.0};
    double dt_{0.01};

    void update();
  
    Vehicle vehicle_;
};
