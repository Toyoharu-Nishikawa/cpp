#include "car.hpp"

Car::Car(double mass)
    : mass_(mass)
{
}

void Car::initialize(
    simulator::State& state
)
{
    state.x = 0.0;
    state.y = 0.0;

    state.vx = 0.0;
    state.vy = 0.0;

    state.yaw = 0.0;
}

void Car::update(
    const simulator::State& state,
    const simulator::Input& input,
    double dt,
    simulator::State& next_state
)
{
    constexpr double engine_force = 5000.0;
    constexpr double drag = 50.0;

    const double force =
        engine_force * input.throttle
        - drag * state.vx;

    const double ax =
        force / mass_;

    next_state.vx =
        state.vx + ax * dt;

    next_state.x =
        state.x + next_state.vx * dt;

    next_state.yaw =
        state.yaw
        + input.steering * dt;

    next_state.vy =
        state.vy;

    next_state.y =
        state.y + next_state.vy * dt;

    next_state.z =
        state.z;

    next_state.vz =
        state.vz;

    next_state.roll =
        state.roll;

    next_state.pitch =
        state.pitch;

    next_state.roll_rate =
        state.roll_rate;

    next_state.pitch_rate =
        state.pitch_rate;

    next_state.yaw_rate =
        input.steering;
}
