// EE 1301
// HW 2A
// Vennela Dupati
//dupat003

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {
char x = 'a';

while (((x>='0')&&(x<= '9'))||((x>='A')&&(x<='Z'))||((x>='a')&&(x<='z'))) {
    cout << "Enter a single digit or an alphabetic character: ";
    cin >> x;
    if ((x>='0')&&(x<= '9')) {
        cout << "You entered " << x << ", which is a number." << endl;
    }
    if ((x>='A')&&(x<='Z')) {
        cout << "You entered " << x << ", which is an uppercase letter." << endl;
    }
    if ((x>='a')&&(x<='z')) {
        cout << "You entered " << x << ", which is a lowercase letter." << endl;
    }
}

cout << "You entered " << x << ", which is not a letter or a number." << endl;





    

}

