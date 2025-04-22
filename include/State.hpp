#pragma once



struct Motor {
    // Constants
    float friction_current = 0;
    float resistance = 10;
    float torque_constant = 1;
    float speed_constant = 1;
    // Input
    float voltage = 0; 
    // Variables
    float rotation_rate = 0; 
    float shaft_torque = 0;
    float current = 0;
};

struct Battery {
    float voltage = 3.7f; 
    float max_voltage = 4.2f;
    float charge_mAh = 100.0f; 
    float capacity_mAh = 380.0f;
    float output_current = 0;
};

struct IMU {
    float acceleration[3] = {0, 0, 0}; 
    float gyroscope[3] = {0, 0, 0}; 
};

struct HardwareObject {
    Battery battery = Battery();
    Motor motors[4] = {Motor(), Motor(), Motor(), Motor()};
    
    IMU imu = IMU();
};


struct RigidBody {
    // World Frame
    float position[3] = {0,0,0}; // Position of the object in 3D space
    float orientation[9] = {0,0,0,0,0,0,0,0,0}; // Orientation of the object in 3D space
    // Body Frame
    float angular_velocity_vector[9] = {0,0,0,0,0,0,0,0,0}; // Angular velocity of the object in 3D space
    float velocity[3] = {0,0,0}; // Velocity of the object in 3D space
    float angular_velocity[3] = {0,0,0}; // Angular velocity of the object
    float acceleration[3] = {0,0,0}; // Force acting on the object in 3D space
    float angular_acceleration[3] = {0,0,0}; // Torque acting on the object in 3D space
    float forces[3] = {0,0,0}; // Force acting on the object in 3D space
    float torques[3] = {0,0,0}; // Torque acting on the object in 3D space
    float mass = 0; // Mass of the object
    float inertia[3] = {0,0,0}; // Inertia of the object
};

struct RotorObject {
    // Constants
    float rotor_inertia = 0.001f; // Inertia of the rotor
    float surface_area = 0.01f; // mm^2 Surface area of the rotor
    float thrust_coefficient = 0.0001f; // Coefficient of thrust produced by the rotor
    float drag_coefficient = 0.01f; // Coefficient of drag produced by the rotor
    // Input
    float torque = 0; // Torque produced by the rotor
    // Variables
    float thrust = 0; // Thrust produced by the rotor
    float angular_velocity = 0; // Angular velocity of the rotor
};

struct DynamicsObject {
    RigidBody rigidbody = RigidBody();
    RotorObject rotors[4] = {RotorObject(), RotorObject(), RotorObject(), RotorObject()};
};


struct DigitalPin {
    bool pinMode = false; // Mode of the digital pin (input/output)
    bool value = false; // State of the digital pin (high/low)
};

struct AnalogPin {
    float value = 0.0f; // Value of the analog pin
};

struct SoftwareObject {
    bool initialized = false; // Flag to check if the software object is initialized
    bool running = false; // Flag to check if the software object is running
    int loop_count = 0;
    float loop_time = 0.1f;
};

struct EmbeddedObject {
    float input_voltage = 3.3f;
    DigitalPin digitalPins[5]; // Array of digital pin objects
    AnalogPin analogPins[5]; // Array of analog pin objects  
};


struct State {
    float time = 0;
    SoftwareObject software = SoftwareObject();
    EmbeddedObject embedded = EmbeddedObject();
    HardwareObject hardware = HardwareObject();
    DynamicsObject dynamics = DynamicsObject();
    
};