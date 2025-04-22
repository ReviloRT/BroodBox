#include "Simulation.hpp"

// Initialize the simulation
void Simulation::init()  {
    state = State();
    wrapper.init(&state);
    hardware.init(&state);
    physics.init(&state);
    hasInitialized = true;
}

// Run the simulation
void Simulation::run()  {
    if (!hasInitialized) { 
        std::cout << "Simulation has not been initalised." << std::endl;
        return;
    }
    const float deltaTime = 0.1f;
    while (true) {
        state.time += deltaTime;
        wrapper.update(deltaTime);
        hardware.update(deltaTime);
        physics.update(deltaTime);
        if (int(state.time/10) % 10 < deltaTime/2.0) {
            std::cout << "Simulation time: " << state.time << " seconds" << std::endl;
        }
        if (state.time >= 1.0f) {return;}
    }
}
