// EE 1301 
// Lab 3 WorkoutA
// Vennela Dupati
// dupat003

#include <iostream>     // cout, etc.
#include <stdlib.h>     // srand, rand
#include <cmath>        // pow
#include <iomanip>      // setprecision
#include <ctime>        // time
using namespace std;

int main(){
    int num;

    cout << "Enter the Number to find square root: ";
    cin >> num;
    
    if (num < 0) {
        cout << "Please enter a valid input(Positive Integer) ." ;
    }
    else {
        double old_guess = num/2.0;
        double new_guess = (( old_guess + (num / old_guess) ) / 2);

        cout << "Guessing..." << endl;
        cout << old_guess << endl;

        while(abs((old_guess - new_guess)/old_guess )> 0.01) {
            cout << new_guess << endl;
            old_guess = new_guess;
            
            new_guess = (( old_guess + num / old_guess ) / 2);
        }

        cout << "The Final Guess: " << new_guess << endl;
        cout << "The Actual Value: " << sqrt(num) << endl;
    }

}