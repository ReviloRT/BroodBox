#include <iostream>
#include "Simulation.h"

int main() {
    try {
        // Initialize the simulation
        Simulation simulation;

        // Run the simulation
        simulation.run();

        std::cout << "Simulation completed successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}