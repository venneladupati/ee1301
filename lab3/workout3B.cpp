// EE 1301 
// Lab 3 WorkoutB
// Vennela Dupati
// dupat003

#include <iostream>     // cout, etc.
#include <stdlib.h>     // srand, rand
#include <cmath>        // pow
#include <iomanip>      // setprecision
#include <ctime>        // time
using namespace std;

double babylonianRoot(double n) {

    double old_guess = n/2.0;
    double new_guess = (( old_guess + (n / old_guess) ) / 2);

    while(abs((old_guess - new_guess)/old_guess )> 0.01) {
        old_guess = new_guess;
        
        new_guess = (( old_guess + n / old_guess ) / 2);
    }

    return new_guess;


}

int main(){

    int num;
    char choice = 'y';

    
    while (choice == 'y') {
        cout << "enter a value: ";
        cin >> num;
        cout << "square root of " << num << " is " << babylonianRoot(num) << endl;
        cout << "continue? (y/n): ";
        cin >> choice;
        if (choice == 'y') {
            cout << endl;
            }
    }

}