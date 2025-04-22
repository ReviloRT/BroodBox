#include <iostream>

class Physics {
public:
    void init();
    void update(float deltaTime);
};


void Physics::init() {
    // Initialize physics engine
    std::cout << "Physics engine initialized." << std::endl;
}

void Physics::update(float deltaTime) {
    // Update physics simulation
    std::cout << "Physics updated with deltaTime: " << deltaTime << std::endl;
}