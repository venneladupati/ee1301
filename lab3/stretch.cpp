// EE 1301 
// Lab 3 Stretch
// Vennela Dupati
// dupat003

#include <iostream>     // cout, etc.
#include <stdlib.h>     // srand, rand
#include <cmath>        // pow
#include <iomanip>      // setprecision
#include <ctime>        // time
using namespace std;

int main() {
    for (int i = 1; i<11; i++) {
        for (int j = 10; j>0; j--){
            cout << right << setw(2) << i* j << " ";
        }
        cout << endl;
    }
}