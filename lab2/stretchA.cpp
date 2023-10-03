// EE1301
// Lab 2 Stretch A
// Vennela Dupati
// dupat003

#include <iostream>     // cout, etc.
#include <iomanip>      // setprecision, fixed
#include <cmath>        // round
#include <time.h>       // time for seeding
using namespace std;

int main() {
    int sides;
    string response;
    srand(time(0));

    cout << "Enter the number of sides on the die: ";
    cin >> sides;

    cout << "You rolled a " << rand() % sides << ". Do you want to roll again? (y/n) ";
    cin >> response;

    while (response == "y") {
        cout << "You rolled a " << rand() % sides << ". Do you want to roll again? (y/n) ";
        cin >> response;
    }
}