// EE 1301
// HW 6A
// Vennela Dupati
// dupat003

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Dice {
private:
    int minRoll;
    int maxRoll;

public:
    // Default constructor
    Dice() : minRoll(1), maxRoll(6) {}

    // Constructor with custom min and max values
    Dice(int min, int max) : minRoll(min), maxRoll(max) {}

    // Roll function
    int roll() const {
        return rand() % (maxRoll - minRoll + 1) + minRoll;
    }
};

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Get user input for min and max values
    int minValue, maxValue;
    cout << "Let's set up a die to roll. What are the minimum and maximum values for this die?" << endl;
    cout << "Minimum Value: ";
    cin >> minValue;
    cout << "Maximum Value: ";
    cin >> maxValue;

    // Create a Dice object with user-defined min and max values
    Dice myDie(minValue, maxValue);

    // Roll the die 10 times and print the results
    cout << "\nThe die is rolled 10 times. The results of those rolls are:" << endl;
    for (int i = 1; i <= 10; ++i) {
        cout << "Roll #" << i << " was: " << myDie.roll() << endl;
    }

    return 0;
}