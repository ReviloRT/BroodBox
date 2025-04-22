# DroneSwarm Simulation Wrapper

The **DroneSwarm Simulation Wrapper** is a tool designed to simulate and test the behavior of the **DroneSwarm** embedded C software in a controlled virtual environment. This wrapper enables developers to validate algorithms, communication protocols, and swarm behaviors without requiring physical hardware.

## Features

- **Virtual Drone Swarm Simulation**: Simulate multiple drones interacting in a 3D environment.
- **Hardware Abstraction**: Test embedded C software without physical drones.
- **Customizable Scenarios**: Define and run various test scenarios for swarm behavior.
- **Real-Time Feedback**: Monitor and debug drone interactions in real-time.
- **Integration Support**: Seamlessly integrate with the DroneSwarm embedded C software.

## Requirements

- Python 3.8+ (for the wrapper)
- Embedded C development environment
- Simulation framework (e.g., Gazebo or Unity)
- Dependencies listed in `requirements.txt`

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/DroneSwarm.git
    cd DroneSwarm/Code/BroodBox
    ```

2. Install dependencies for the wrapper:
    ```bash
    pip install -r requirements.txt
    ```

3. Set up the simulation environment (Gazebo or Unity) as per the documentation.

## Usage

1. Launch the simulation wrapper:
    ```bash
    python simulation_wrapper.py
    ```

2. Configure the simulation parameters in `config.yaml`.

3. Compile and load your embedded C software into the simulation environment.

4. Observe and debug the swarm behavior using the provided tools.
