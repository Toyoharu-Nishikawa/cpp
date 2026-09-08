#include <iostream>
#include <memory>

#include "simulator/input.hpp"
#include "simulator/simulator.hpp"
#include "car.hpp"
// #include "SimpleDrone.hpp"

int main()
{
    simulator::Simulator simulator;

    Input input;
    input.throttle = 1.0;
    input.steering = 0.0;

    simulator.set_input(input);

    auto car =
        std::make_unique<Car>(
            1500.0
        );

    simulator.set_vehicle(
        std::move(car)
    );

    simulator.set_time_step(
        0.01
    );

    simulator.set_duration(
        5.0
    );

    simulator.run();

    const auto& state =
        simulator.get_state();

    std::cout
        << "\nFinal state:\n"
        << "x = " << state.x << '\n'
        << "y = " << state.y << '\n'
        << "vx = " << state.vx << '\n'
        << "vy = " << state.vy << '\n';

    return 0;
}
