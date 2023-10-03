// EE 1301
// HW 2B
// Vennela Dupati
//dupat003

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {

int hour;
char meridiem;

cout << "Enter the current time (A for AM, P for PM): ";
cin >> hour >> meridiem;

char dir;
int difference;

cout << "How many hours forward or backward do you want to move the clock (F for forward, B for backward): ";
cin >> dir >> difference;

if (dir == 'F') {
for (int i = 1; i < difference+1; i++) {
    if (hour == 12) {
        hour = 0;
        if (meridiem == 'A') {
            meridiem = 'P';
        }
        else {
            meridiem = 'A';
        } 
    }

    hour += 1;
}
}

if (dir == 'B') {
for (int i = 1; i < difference+1; i++) {
    if (hour == 0) {
        hour = 12;
        if (meridiem == 'A') {
            meridiem = 'P';
        }
        else {
            meridiem = 'A';
        } 
    }

    hour -= 1;
}
}

cout << "The new time is: " << hour << " " << meridiem << "M";
}