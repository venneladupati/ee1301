#include <iostream>

using namespace std;

// Function to calculate momentum
double* momentum(double velocity[3], double mass) {
    // Dynamically allocate memory for the momentum array
    double* result = new double[3];

    // Calculate momentum for each component
    for (int i = 0; i < 3; ++i) {
        result[i] = mass * velocity[i];
    }

    // Return the dynamically allocated array
    return result;
}

int main() {
    // Declare variables for velocity and mass
    double velocity[3];
    double mass;

    // Get user input for velocity components
    cout << "Enter the x-component of velocity: ";
    cin >> velocity[0];
    cout << "Enter the y-component of velocity: ";
    cin >> velocity[1];
    cout << "Enter the z-component of velocity: ";
    cin >> velocity[2];

    // Get user input for mass
    cout << "Enter the mass: ";
    cin >> mass;

    // Call the momentum function
    double* result = momentum(velocity, mass);

    // Display the momentum components
    cout << "Momentum in x-direction: " << result[0] << endl;
    cout << "Momentum in y-direction: " << result[1] << endl;
    cout << "Momentum in z-direction: " << result[2] << endl;

    // Deallocate the dynamically allocated memory
    delete[] result;

    return 0;
}