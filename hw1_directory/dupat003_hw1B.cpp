// EE 1301 
// HW 1B
// Vennela Dupati
// dupat003

#include <iostream>     // cout, etc.
#include <iomanip>      // setprecision, fixed
#include <cmath>        
using namespace std;

int main() {

    string type;

    cout << "Are input components int or float (i/f)? ";
    cin >> type;


    if (type=="i"){
         
        cout << fixed;
        cout << setprecision(2);

        int r;
        int g;
        int b;

        cout << "Input r, g, b: ";
        cin >> r >> g >> b;

        float finalR;
        float finalG;
        float finalB;

        finalR = r/255.00;
        finalG = g/255.00;
        finalB = b/255.00;


        cout << "Float representation: " << finalR << ", " << finalG << ", " << finalB << endl;
    }

    else if (type == "f"){


        cout << fixed;
        cout << setprecision(0);
        
        double r;
        double g;
        double b;

        cout << "Input r, g, b: ";
        cin >> r >> g >> b;

        r = r * 255;
        g = g* 255;
        b = b * 255;

        cout << "Integer representation: " << r << ", " << g << ", " << b << endl;

    }

    else {
        cout << "Invalid option." << endl;
    }


}