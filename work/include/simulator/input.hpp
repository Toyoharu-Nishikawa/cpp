#pragma once

namespace simulator
{

struct Input
{
    // Generic vehicle input

    // -1.0 ~ 1.0
    double throttle = 0.0;

    // -1.0 ~ 1.0
    double steering = 0.0;

    // 0.0 ~ 1.0
    double brake = 0.0;
};

}
