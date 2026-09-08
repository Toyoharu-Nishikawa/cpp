#include "simulator/simulator.hpp"

#include <iostream>
#include <stdexcept>

namespace simulator
{

Simulator::Simulator()
    : dt_(0.01),
      duration_(10.0)
{
}

Simulator::~Simulator() = default;


void Simulator::set_input(
    const Input& input
)
{
    input_ = input;
}

void Simulator::set_vehicle(
    std::unique_ptr<Vehicle> vehicle
)
{
    if (!vehicle)
    {
        throw std::invalid_argument(
            "Vehicle must not be null."
        );
    }

    vehicle_ = std::move(vehicle);

    vehicle_->initialize(state_);
}

void Simulator::set_time_step(
    double dt
)
{
    if (dt <= 0.0)
    {
        throw std::invalid_argument(
            "dt must be greater than zero."
        );
    }

    dt_ = dt;
}

void Simulator::set_duration(
    double duration
)
{
    if (duration < 0.0)
    {
        throw std::invalid_argument(
            "duration must not be negative."
        );
    }

    duration_ = duration;
}

const State& Simulator::get_state() const
{
    return state_;
}

void Simulator::run()
{
    if (!vehicle_)
    {
        throw std::runtime_error(
            "Vehicle has not been set."
        );
    }

    double time = 0.0;

    State next_state;

    while (time < duration_)
    {
        vehicle_->update(
            state_,
            input_,
            dt_,
            next_state
        );

        state_ = next_state;

        time += dt_;

        std::cout
            << "t=" << time
            << " x=" << state_.x
            << " y=" << state_.y
            << " vx=" << state_.vx
            << " vy=" << state_.vy
            << '\n';
    }
}

}
