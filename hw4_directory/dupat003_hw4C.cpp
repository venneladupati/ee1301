// EE 1301 
// HW 4C
// Vennela Dupati
// dupat003

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){

    // declare variables
    char x;
    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;


    //open file
    ifstream inFS; 
    inFS.open("input_files/blahblah.txt");

    // read in file by character and increment corresponding vowel counter if it is in fact a vowel
    while (!inFS.eof()) {
        inFS >>x;
        if ((x == 'A') || (x == 'a')) {
            aCount++;
        }
        else if ((x == 'E') || (x == 'e')) {
            eCount++;
        }
        else if ((x == 'I') || (x == 'i')) {
            iCount++;
        }
        else if ((x == 'O') || (x == 'o')) {
            oCount++;
        }
        else if ((x == 'U') || (x == 'u')) {
            uCount++;
        }

    }

    // figure out which vowel shows up the most (winner)
    int max = aCount;
    char let = 'A';
    if (eCount > max) {
        max = eCount;
        char let = 'E';
    }
    if (iCount > max) {
        max = iCount;
        char let = 'I';
    }
    if (oCount > max) {
        max = oCount;
        char let = 'O';
    }
    if (uCount > max) {
        max = uCount;
        char let = 'U';
    }

    // close file
    inFS.close();

    // print out each vowel and its count
    // also print out winner
    cout << "The result are in!"<<endl;
    cout << "A/a recieved " << aCount << " votes" << endl;
    cout << "E/e recieved " << eCount << " votes" << endl;
    cout << "I/i recieved " << iCount << " votes" << endl;
    cout << "O/o recieved " << oCount << " votes" << endl;
    cout << "U/u recieved " << uCount << " votes" << endl;
    cout << "The winner is the letter \"" << let << "\"!";

    // create output file and input values into it
    ofstream outputFile("output_files/election_results.txt");
    outputFile << "A," << aCount << endl;
    outputFile << "E," << eCount << endl;
    outputFile << "I," << iCount << endl;
    outputFile << "O," << oCount << endl;
    outputFile << "U," << uCount << endl;
    
    //close output file
    outputFile.close();
    
}