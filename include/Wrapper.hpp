#pragma once

#include <iostream>
#include "State.hpp"

class Wrapper {
private:
    State* state;

public:
    void init(State* state);
    void update(float deltaTime);
};