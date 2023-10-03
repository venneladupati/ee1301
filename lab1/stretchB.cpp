#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x;
    int max;
    cout << "Enter a number: "<< endl;
    cin >> max;
    x = max;

    while (x != 0) {
        cout << "Enter a number: "<< endl;
        cin >> x;
        if (x>max){
            max = x;
        }
    }

    cout << max << endl;


}