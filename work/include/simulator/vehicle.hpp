#pragma once

#include "state.hpp"
#include "input.hpp"

namespace simulator
{

class Vehicle
{
public:

    virtual ~Vehicle() = default;

    virtual void initialize(
        State& state
    ) = 0;

    virtual void update(
        const State& state,
        const Input& input,
        double dt,
        State& next_state
    ) = 0;
};

}
