#pragma once

#include <memory>

#include "state.hpp"
#include "input.hpp"
#include "vehicle.hpp"

namespace simulator
{

class Simulator
{
public:

    Simulator();

    ~Simulator();

    void set_input(
        const Input& input
    );

    void set_vehicle(
        std::unique_ptr<Vehicle> vehicle
    );

    void set_time_step(
        double dt
    );

    void set_duration(
        double duration
    );

    void run();

    const State& get_state() const;

private:

    std::unique_ptr<Vehicle> vehicle_;

    State state_;

    Input input_;

    double dt_;
    double duration_;
};

}
