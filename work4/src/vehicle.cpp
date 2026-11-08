#include "vehicle.hpp"
#include "vehicle-state.hpp"

void Vehicle::setInitialState(const VehicleState& state){
  state_ = state;
}

void Vehicle::update(double time, double dt){
  state_.position += state_.velocity*dt;
  state_.velocity += state_.acceleration*dt;
}

