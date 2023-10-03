// EE1301
// Lab 2 Warmup
// Vennela Dupati
// dupat003
#include <iostream>     // cout, etc.
#include <iomanip>      // setprecision, fixed
#include <cmath>        // round
using namespace std;

int main() {
    double c = 3e10;
    double L;
    double v;

    cout << "Enter L: ";
    cin >> L;
    cout << "Enter v: ";
    cin >> v;

    cout << "Relative Length = " << (L*sqrt(1-(v*v)/(c*c)));
}
