#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    int answer;

    cout << "What number's factorial do you want to compute?: ";
    cin >> num;

        for (int i =1; i<num+1; i++) {
            if (i==1) {
                answer = 1;
            }
            else {
                answer *=i;
            }
        }

    cout << answer << endl;
    return 0;

}