// EE 1301 
// HW 3B
// Vennela Dupati
// dupat003

#include <iostream>     // cout, etc.
#include <stdlib.h>     // srand, rand
#include <cmath>        // pow
#include <iomanip>      // setprecision
#include <ctime>        // time
using namespace std;

int randWalk(int oldValue, int updateSize) {


    int num = rand()%(updateSize-(-updateSize) + 1) + (-updateSize);
    int newValue = oldValue + num;

    if (newValue > 255){
        newValue = 255;
    }
    else if (newValue < 0) {
        newValue = 0;
    }

    return newValue;
}


int main() {
    int intialValue;
    int iterations;
    int updateSize;

    cout << "Please enter an initial integer value in the range [0,255]: ";
    cin >> intialValue;

    while ( (intialValue > 255) || (intialValue < 0) ) {
        cout << "Value must be between 0 and 255. Please enter an initial value in the range [0,255]: ";
        cin >> intialValue;

    }

    cout << "Please enter the desired number of iterations: ";
    cin >> iterations;

    cout << "Please enter the size of each possible update for each iteration: ";
    cin >> updateSize;

    srand(time(0));
    for (int i = 1; i < iterations +1; i++){
        cout << "Value at iteration # " << i << " is: " << randWalk(intialValue, updateSize)<< endl;
    }

}

