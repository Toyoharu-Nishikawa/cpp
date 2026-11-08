#pragma once

#include "vehicle-state.hpp"

struct Input{
  double max_time{};
  double dt{};
  VehicleState vehicle_state{};
};
