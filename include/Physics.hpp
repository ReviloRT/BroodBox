#pragma once

#include <iostream>
#include "State.hpp"

class Physics {
private:
    State* state;
    void rotorFunction(RotorObject &rotor, float motor_torque, float deltaTime);
    void rotation(float* rotationMatrix, float roll, float pitch, float yaw);
    void rotateBodyToWorldFrame(const float* body, float* world);
    void rotateWorldToBodyFrame(const float* world, float* body);

public:
    void init(State* state);
    void update(float deltaTime);
    void updateRotors(float deltaTime);
    void updateDynamics(float deltaTime);
};  