#pragma once

#include <iostream>
#include "Physics.hpp"
#include "Hardware.hpp"
#include "Wrapper.hpp"
#include "State.hpp"

class Simulation {
private:
    State state;
    Physics physics;
    Hardware hardware;
    Wrapper wrapper;

    bool hasInitialized = false;
public:
    void init();
    void run();
};
