#include "../src/simulator.hpp"
#include "../src/input.hpp"

#include <iostream>

int main(){
  const Input input{
    .max_time      = 5  ,
    .dt            = 0.1,
    .vehicle_state = {
      .position     = 0.0,
      .velocity     = 0.0,
      .acceleration = 1.0,
    },
  };

  Simulator simulator;

  simulator.loadInput(input);
  simulator.run();
  
  const VehicleState& vehicle_state = simulator.getResult();

  std::cout << "simuation finished" << "\n";
  std::cout << "position: "<< vehicle_state.position << "\n";
  std::cout << "velocity: "<< vehicle_state.velocity << "\n";
  std::cout << "acceleration: "<< vehicle_state.acceleration << "\n";
  return 0;

}
