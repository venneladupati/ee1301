// EE 1301
// HW 2C
// Vennela Dupati
//dupat003

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {

    int value;
    cout << "How many values do you want on each wheel? ";
    cin >> value;

    while ((value != -1)) {

        if (value >= 1) {
        srand(time(0));
        int rand1 = rand() % value;
        int rand2 = rand() % value;
        int rand3 = rand() % value;
        int rand4 = rand() % value;

        if ((rand1==rand2)&&(rand2==rand3)&&(rand3==rand4)) {
            cout << "The wheels spin to give: " << rand1 << " " << rand2 << " " << rand3 << " " << rand4 << ". Eureka!" << endl;
        }
        else {
            cout << "The wheels spin to give: " << rand1 << " " << rand2 << " " << rand3 << " " << rand4 << ". You lose." << endl;
        }
        }

        else {
            cout << "Please try again with an acceptable input (-1 or any positive number).";
        }

        cout << "How many values do you want on each wheel? ";
        cin >> value;

    }
    

    if (value == -1) {
        cout << "OK, goodbye.";
    }


}
