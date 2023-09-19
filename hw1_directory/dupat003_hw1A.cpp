// EE 1301 
// HW 1A
// Vennela Dupati
// dupat003

#include <iostream>     
#include <iomanip>      
#include <cmath>        
using namespace std;

int main() {

    cout << fixed;
    cout << setprecision(2);

double radius;
double height;
double volume;
double surfaceArea;
double volumeFluid;
double surfaceAreaFluid;

cout << "Input the radius of the sphere: ";
cin >> radius;
cout << "Input the height of the fluid: ";
cin >> height;

volume = 4.0/3.0 * M_PI *radius * radius *radius;
surfaceArea = 4.0 * M_PI *radius * radius;
volumeFluid = 1.0/3.0 * M_PI * height * height * (3*radius-height);
surfaceAreaFluid = 2.0 * M_PI * radius * height;

cout << "Volume of the entire tank: " << volume << endl;
cout << "Surface area of the entire tank: " << surfaceArea << endl;
cout << "Volume of the fluid: " << volumeFluid << endl;
cout << "Surface area covered by the fluid: " << surfaceAreaFluid << endl;






return 0;
}

