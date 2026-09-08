#pragma once

namespace simulator
{

struct State
{
    // Position [m]
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    // Velocity [m/s]
    double vx = 0.0;
    double vy = 0.0;
    double vz = 0.0;

    // Orientation [rad]
    double roll = 0.0;
    double pitch = 0.0;
    double yaw = 0.0;

    // Angular velocity [rad/s]
    double roll_rate = 0.0;
    double pitch_rate = 0.0;
    double yaw_rate = 0.0;
};

}
