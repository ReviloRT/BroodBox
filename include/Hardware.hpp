#pragma once

#include <iostream>
#include "State.hpp"

class Hardware {
private:
    State* state;

    void motorFunction(Motor &motor, float voltage);
    void batteryFunction(Battery &battery, float current, float deltaTime);
    void imuFunction(IMU &imu, RigidBody &physics);

public:
    void init(State* state);
    void update(float deltaTime);
    void updateMotors();
    void updateBattery(float deltaTime);
    void updateIMU();
};

