#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Function to generate a random 3-element array of doubles in the range [-100.0, +100.0]
double* randVec() {
    double* result = new double[3];

    for (int i = 0; i < 3; ++i) {
        result[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
    }

    return result;
}

// Function to calculate momentum
double* momentum(double velocity[3], double mass) {
    double* result = new double[3];

    for (int i = 0; i < 3; ++i) {
        result[i] = mass * velocity[i];
    }

    return result;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Number of items
    const int numItems = 1000;

    // Array of pointers to store momentum vectors
    double** momentumArray = new double*[numItems];

    // Generate momentum vectors for 1000 items with random velocities and masses
    for (int i = 0; i < numItems; ++i) {
        double* velocity = randVec();
        double mass = ((double)rand() / RAND_MAX) * 9.0 + 1.0; // Random mass in [1.0, 10.0]
        momentumArray[i] = momentum(velocity, mass);

        // Deallocate memory for velocity array
        delete[] velocity;
    }

    // Calculate the average momentum vector component by component
    double averageMomentum[3] = {0.0, 0.0, 0.0};
    for (int i = 0; i < numItems; ++i) {
        for (int j = 0; j < 3; ++j) {
            averageMomentum[j] += momentumArray[i][j];
        }
    }

    // Calculate the average by dividing each component by the number of items
    for (int j = 0; j < 3; ++j) {
        averageMomentum[j] /= numItems;
    }

    // Display the average momentum vector
    cout << "Average Momentum Vector:" << endl;
    cout << "x-component: " << averageMomentum[0] << endl;
    cout << "y-component: " << averageMomentum[1] << endl;
    cout << "z-component: " << averageMomentum[2] << endl;

    // Deallocate memory for momentum vectors
    for (int i = 0; i < numItems; ++i) {
        delete[] momentumArray[i];
    }
    delete[] momentumArray;

    return 0;
}