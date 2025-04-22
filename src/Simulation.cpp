#include <iostream>


class Simulation {
private:
    Physics physics;
    Wrapper wrapper;
public:
    void init();
    void run();
};


// Initialize the simulation
void Simulation::init()  {
    wrapper.init();
    physics.init();
}

// Run the simulation
void Simulation::run()  {
    const float deltaTime = 0.1f;
    float now = 0;
    while (true) {
        now += deltaTime;
        wrapper.update(deltaTime);
        physics.update(deltaTime);
        if (now % 1.0f < deltaTime/2.0) {
            std::cout << "Simulation time: " << now << " seconds" << std::endl;
        }
        if (now >= 10.0f) {return;}
    }
}
