#pragma once

#include "vehicle-state.hpp"

class Vehicle{
  public:
    virtual ~Vehicle() = default;

    void setInitialState(const VehicleState& state);

    void update(double time, double dt);

    const VehicleState& getState() const{
        return state_;
    }

  protected:
    VehicleState state_{};
};
