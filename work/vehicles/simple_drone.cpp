#include "simple_drone.hpp"

void SimpleDrone::initialize(
    simulator::State& state
)
{
    state.x = 0.0;
    state.y = 0.0;
    state.z = 10.0;

    state.vx = 0.0;
    state.vy = 0.0;
    state.vz = 0.0;
}

void SimpleDrone::update(
    const simulator::State& state,
    const simulator::Input& input,
    double dt,
    simulator::State& next_state
)
{
    // Simple drone model

    const double vertical_acceleration =
        input.throttle * 10.0 - 9.81;

    next_state.vz =
        state.vz
        + vertical_acceleration * dt;

    next_state.z =
        state.z
        + next_state.vz * dt;

    next_state.x =
        state.x
        + state.vx * dt;

    next_state.y =
        state.y
        + state.vy * dt;

    next_state.vx =
        state.vx;

    next_state.vy =
        state.vy;

    next_state.roll =
        state.roll;

    next_state.pitch =
        state.pitch;

    next_state.yaw =
        state.yaw;

    next_state.roll_rate =
        state.roll_rate;

    next_state.pitch_rate =
        state.pitch_rate;

    next_state.yaw_rate =
        state.yaw_rate;
}
