#include <iostream>
#include <stdlib.h>  
using namespace std;

void minutesToTime(int minute_value, int& hours, int& mins){
        hours = minute_value/60;
        mins = minute_value % 60;
    }

int main(){
    int minute_value;

    int hour;
    int min;

    int& hours = hour;
    int& mins = min;

    char ans = 'y';

    while (ans == 'y') {
        cout << "Enter a number of minutes: ";
        cin >> minute_value;

        cout << "Hours:minutes is ";
        minutesToTime(minute_value,hours,mins);

        cout << hours << ":";
        if (mins > 10) {
            cout << mins;
        }
        else if (mins > 0) {
            cout << "0" <<mins;
        }
        else {
            cout << "00";
        }
        cout << endl;

        cout << "Continue? (y/n): ";
        cin >> ans;
    }
    
}