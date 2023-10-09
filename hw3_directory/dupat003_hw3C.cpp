// EE 1301 
// HW 3C
// Vennela Dupati
// dupat003

#include <iostream>     // cout, etc.
#include <stdlib.h>     // srand, rand
#include <cmath>        // pow
#include <iomanip>      // setprecision
#include <ctime>        // time
using namespace std;

int spin_the_wheels(int d, int w) {
    int rand1;
    int rand2;

    rand1 = rand() % d  +1 ;

    for (int i = 0; i < w-1; i++) {
        rand2 = rand() % d + 1;
        if (rand1 != rand2) {
            return 0;
        }
        else {
            rand1 = rand2;
        }
     }

    return 1;
 }


int main() {

    srand(time(NULL));

    for (int w = 3; w<7; w++) {
        for (int d= 9; d<28; d=d+3){
            int count = 0;
            for (int i = 0; i<1000000; i++) {
                if (spin_the_wheels(d,w)==1) {
                    count++;
                }
            }
            
            cout << "w=" << w << ", d=" << d << ": Simulated probability = m/n = " << (count/1000000.0000000000)*100 << "%. Theoretical probability = " << (d / pow(d,w) )* 100 << "%."<<endl;
        }
    }
}


   