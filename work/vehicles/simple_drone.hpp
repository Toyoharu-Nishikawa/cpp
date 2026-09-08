#pragma once

#include "simulator/vehicle.hpp"

class SimpleDrone : public simulator::Vehicle
{
public:

    void initialize(
        simulator::State& state
    ) override;

    void update(
        const simulator::State& state,
        const simulator::Input& input,
        double dt,
        simulator::State& next_state
    ) override;
};
