// EE 1301 
// Quiz2B
// Vennela Dupati
// dupat003

#include <iostream>     // cout, etc.
#include <stdlib.h>     // srand, rand
#include <cmath>        // pow
#include <iomanip>      // setprecision
#include <ctime>        // time
using namespace std;

// Modeled after a typical 20 sided-die roll (my family likes board games); should return a random value from 1-20 (inclusive)
int rollDie() {
    int roll = (rand() % 20) + 1;
    return roll;
}

// outputs false if inputted number is divisible by any number from 3-13
bool isKindaPrime(int x) {
    for (int i=3;i<14; i++){
        if (x%i == 0) {
            return false;
        }
    }

    return true;
}

// sets the seed of the random function to time, ensuring new set of random numbers each time program is run
// rolls die, gets random number, and evaluates whether or not roll value is divisible by any number from 3-13
// outputs whether or not roll value is divisible by any number from 3-13 (whether or not the number is KindaPrime)
int main() {

    srand(time(NULL));

    for (int i = 0; i<10; i++){
        int roll = rollDie();
        if ((isKindaPrime(roll)) == true) {
            cout << "Roll: " << roll << " is KindaPrime"<<endl;
        }
        else {
            cout << "Roll: " << roll << " is not KindaPrime"<<endl;
        }
    }
}
