// EE 1301 
// HW 4B
// Vennela Dupati
// dupat003

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){

    //declare variables
    double num= 0;
    string x;

    // open csv file
    ifstream inFS; 
    inFS.open("statistics.csv");

    // get header out of the way
    string header;
    getline(inFS, header);

    int max = 0;

    // read in grade and frequency, print grade, and print Xs based on frequency
   while (getline(inFS, x, ',') && inFS >> num) {
        cout << x;

        if (num > max) {
            max = num;
        }

        for (int i = 0; i<num;i++){
            cout << " X";
        }

    }

    cout << endl;

    // print out equal sign footer
    int numEquals = 2 * max + 2;

    for (int i = 0; i < numEquals; i++) {
        cout << "=";
    }

    cout << endl << "  ";

    // print out numbering elements on bottom
    for (int i = 1; i < max + 1; i++) {
        cout << i << " ";
    }

    //close file
    inFS.close();

    
}


