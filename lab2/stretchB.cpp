// EE1301
// Lab 2 Stretch B
// Vennela Dupati
// dupat003

#include <iostream>     // cout, etc.
#include <iomanip>      // setprecision, fixed
#include <cmath>        // round
#include <time.h>       // time for seeding
using namespace std;

int main() {
    int a;
    char oper;
    int b;
    cout << "Enter an equation: ";
    cin >> a >> oper >> b;
    

    if (oper == '+'){
        cout << a << oper << b << " = " << a+b;
    }
    else if (oper == '-'){
        cout << a << oper << b << " = " << a-b;
    }
    else if (oper == '*'){
        cout << a << oper << b << " = " << a*b;
    }
    else {
        cout << a << oper << b << " = " << a/b;
    }

}
