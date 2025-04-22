#include "Wrapper.hpp"


void Wrapper::init(State* state){
    this->state = state;
    // Initialize wrapper engine
    std::cout << "Wrapper engine initialized." << std::endl;
}

void Wrapper::update(float deltaTime) {
    if (state == nullptr) {
        std::cerr << "State is not initialized." << std::endl;
        return;
    }
    std::cout << "Wrapper updated with deltaTime: " << deltaTime << std::endl;
}
