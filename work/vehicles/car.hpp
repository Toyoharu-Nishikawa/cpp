#pragma once

#include "simulator/vehicle.hpp"

class Car : public simulator::Vehicle
{
public:

    explicit Car(
        double mass
    );

    void initialize(
        simulator::State& state
    ) override;

    void update(
        const simulator::State& state,
        const simulator::Input& input,
        double dt,
        simulator::State& next_state
    ) override;

private:

    double mass_;
};

