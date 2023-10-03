#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int x = 20;
    double h = 1e-9;
    double derivative;

    derivative = ((pow(x+h,3)-pow(x,3))/(h));
    cout << derivative<< endl;
    
    return 0;
    
}