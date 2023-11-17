// EE 1301 
// HW 5B
// Vennela Dupati
// dupat003

#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int main(int argc, char *argv[]) {

    //read in arguments and convert them to ints
    int numRows = atoi(argv[1]);
    int numColumns = atoi(argv[2]);
    int arrayMax = atoi(argv[3]);

    // read random as null
    srand(time(NULL));

    ofstream outputFile("randArray.txt");

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            int randNum = rand() % (2 * arrayMax + 1) - arrayMax;
            outputFile << randNum;

            if (j < numColumns - 1) {
                outputFile << " ";
            }
        }

        outputFile << endl;
    }

    outputFile.close();
    return 0; 
}