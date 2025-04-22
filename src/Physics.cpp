

#include "Physics.hpp"


void Physics::init(State* state){
    this->state = state;
    // Initialize physics engine
    std::cout << "Physics engine initialized." << std::endl;
}

void Physics::update(float deltaTime) {
    if (state == nullptr) {
        std::cerr << "State is not initialized." << std::endl;
        return;
    }
    updateRotors(deltaTime);
    updateDynamics(deltaTime);
    std::cout << "Physics updated with deltaTime: " << deltaTime << std::endl;
}

void Physics::rotorFunction(RotorObject &rotor, float motor_torque, float deltaTime) {
    // Update rotor state
    rotor.torque = motor_torque - rotor.drag_coefficient * rotor.angular_velocity * rotor.angular_velocity * rotor.surface_area;
    rotor.angular_velocity += (rotor.torque / rotor.rotor_inertia) * deltaTime;
    rotor.thrust = rotor.thrust_coefficient * rotor.angular_velocity * rotor.angular_velocity * rotor.surface_area;
}

void Physics::updateRotors(float deltaTime) {
    rotorFunction(state->dynamics.rotors[0], state->hardware.motors[0].shaft_torque, deltaTime);
    rotorFunction(state->dynamics.rotors[1], state->hardware.motors[1].shaft_torque, deltaTime);
    rotorFunction(state->dynamics.rotors[2], state->hardware.motors[2].shaft_torque, deltaTime);
    rotorFunction(state->dynamics.rotors[3], state->hardware.motors[3].shaft_torque, deltaTime);
}
void Physics::rotateBodyToWorldFrame(const float* body, float* world) {
    for (int i = 0; i < 3; i++) {
        world[i] = 0.0f;
        for (int j = 0; j < 3; j++) {
            world[i] += state->dynamics.rigidbody.orientation[i * 3 + j] * body[j];
        }
    }
}

void Physics::rotateWorldToBodyFrame(const float* world, float* body) {
    for (int i = 0; i < 3; i++) {
        body[i] = 0.0f;
        for (int j = 0; j < 3; j++) {
            body[i] += state->dynamics.rigidbody.orientation[j * 3 + i] * world[j]; // Transpose of the rotation matrix
        }
    }
}

void Physics::updateDynamics(float deltaTime) {

    state->dynamics.rigidbody.forces[0] = state->dynamics.rotors[0].thrust;
    state->dynamics.rigidbody.forces[0] += state->dynamics.rotors[1].thrust;
    state->dynamics.rigidbody.forces[0] += state->dynamics.rotors[2].thrust;
    state->dynamics.rigidbody.forces[0] += state->dynamics.rotors[3].thrust;
    state->dynamics.rigidbody.forces[1] = 0;
    state->dynamics.rigidbody.forces[2] = 0;
    
    for (int i = 0; i < 3; i++) {
        // state->dynamics.rigidbody.acceleration[i]            = state->dynamics.rigidbody.forces[i] / state->dynamics.rigidbody.mass;
        // state->dynamics.rigidbody.angular_acceleration[i]    = state->dynamics.rigidbody.torques[i] / state->dynamics.rigidbody.inertia[i];
        // state->dynamics.rigidbody.position[i]               += state->dynamics.rigidbody.velocity[i] * deltaTime + 0.5f * state->dynamics.rigidbody.acceleration[i] * deltaTime * deltaTime;
        // state->dynamics.rigidbody.velocity[i]               += state->dynamics.rigidbody.acceleration[i] * deltaTime;
        // state->dynamics.rigidbody.orientation[i]            += state->dynamics.rigidbody.angular_velocity[i] * deltaTime + 0.5f * state->dynamics.rigidbody.angular_acceleration[i] * deltaTime * deltaTime;
        // state->dynamics.rigidbody.angular_velocity[i]       += state->dynamics.rigidbody.angular_acceleration[i] * deltaTime;
    }

    std::cout << "Position: (" << state->dynamics.rigidbody.position[0] << ", " << state->dynamics.rigidbody.position[1] << ", " << state->dynamics.rigidbody.position[2] << ")" << std::endl;
    std::cout << "Velocity: (" << state->dynamics.rigidbody.velocity[0] << ", " << state->dynamics.rigidbody.velocity[1] << ", " << state->dynamics.rigidbody.velocity[2] << ")" << std::endl;
    std::cout << "Forces: (" << state->dynamics.rigidbody.forces[0] << ", " << state->dynamics.rigidbody.forces[1] << ", " << state->dynamics.rigidbody.forces[2] << ")" << std::endl;
}