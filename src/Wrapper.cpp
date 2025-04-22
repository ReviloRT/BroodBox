#include <iostream>

class Wrapper {
public:
    void init();
    void update(float deltaTime);
};


void Wrapper::init() {
    // Initialize wrapper engine
    std::cout << "Wrapper engine initialized." << std::endl;
}

void Wrapper::update(float deltaTime) {
    // Update wrapper simulation
    std::cout << "Wrapper updated with deltaTime: " << deltaTime << std::endl;
}

