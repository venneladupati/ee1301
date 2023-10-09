// EE 1301 
// HW 3A
// Vennela Dupati
// dupat003

#include <iostream>     // cout, etc.
#include <stdlib.h>     // srand, rand
#include <cmath>        // pow
#include <iomanip>      // setprecision
#include <ctime>        // time
using namespace std;

int main() {
    int num;
    cout << "Enter an integer from -50 to 50: ";
    cin >> num;

    while (num!= 0) {
        if ((num >= -50) && (num <= 50)) {
            if (num > 0) { 
                for (int i = 1; i<num+1; i++) {
                    for (int j = 0; j < i; j++) {
                        cout << i;
                    }
                    cout << endl;
                }
            }
            else {
                for (int i = abs(num); i>0; i--) {
                    for (int j = 0; j < i; j++) {
                        cout << i;
                    }
                    cout << endl;
            }
            }

            cout << "Enter an integer from -50 to 50: ";
            cin >> num;
        }

        else {
            cout << "Sorry, you have entered an out of bounds input! Please enter a valid value." << endl;
            cout << "Enter an integer from -50 to 50: ";
            cin >> num;

        }



    }

    cout << "Goodbye.";    


}
