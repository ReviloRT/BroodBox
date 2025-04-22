#include "Hardware.hpp"

void Hardware::motorFunction(Motor &motor, float voltage) {
    motor.voltage = voltage;
    motor.current = (voltage-motor.rotation_rate/motor.speed_constant)/motor.resistance;
    motor.shaft_torque = (motor.current-motor.friction_current) / motor.torque_constant;
}

void Hardware::batteryFunction(Battery &battery, float current, float deltaTime) {
    // Update battery state
    battery.output_current = current;
    float charge_draw = current * 1000 * battery.voltage * deltaTime / 60.0f / 60.0f;
    battery.charge_mAh -= charge_draw;
    if (battery.charge_mAh < 0) {
        battery.charge_mAh = 0;
    }
    // TODO, impliment nonlinear model
    battery.voltage = battery.max_voltage * (battery.charge_mAh / battery.capacity_mAh);   
}

void Hardware::imuFunction(IMU &imu, RigidBody &physics) {
    // Update IMU data
    // TODO add non-centered IMU functions
    imu.acceleration[0] = physics.acceleration[0];
    imu.acceleration[1] = physics.acceleration[1];
    imu.acceleration[2] = physics.acceleration[2];
    imu.gyroscope[0] = physics.angular_velocity[0];
    imu.gyroscope[1] = physics.angular_velocity[1];
    imu.gyroscope[2] = physics.angular_velocity[2];
}

void Hardware::init(State* state){
    this->state = state;
    // Initialize physics engine
    std::cout << "Hardware engine initialized." << std::endl;
}

void Hardware::update(float deltaTime) {
    if (state == nullptr) {
        std::cerr << "State is not initialized." << std::endl;
        return;
    }
    updateMotors();
    updateBattery(deltaTime);
    updateIMU();
    std::cout << "Hardware updated with deltaTime: " << deltaTime << std::endl;
}



void Hardware::updateMotors() {
    // motorFunction(state->hardware.motors[0], state->embedded.analogPins[0].value);
    motorFunction(state->hardware.motors[0], 3.6f);
    motorFunction(state->hardware.motors[1], state->embedded.analogPins[1].value);
    motorFunction(state->hardware.motors[2], state->embedded.analogPins[2].value);
    motorFunction(state->hardware.motors[3], state->embedded.analogPins[3].value);
}
void Hardware::updateBattery(float deltaTime) {
    float current = 0;
    current += state->hardware.motors[0].current;
    current += state->hardware.motors[1].current;
    current += state->hardware.motors[2].current;
    current += state->hardware.motors[3].current;
    batteryFunction(state->hardware.battery, current, deltaTime);
}

void Hardware::updateIMU() {
    imuFunction(state->hardware.imu, state->dynamics.rigidbody);
}