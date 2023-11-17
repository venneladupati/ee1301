// EE 1301 
// HW 4A
// Vennela Dupati
// dupat003

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){

    // declare variables
    double num= 0;
    string x;
    string y;
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    int dCount = 0;
    int fCount = 0;

    //open file
    ifstream inFS; 
    inFS.open("grades.txt");

    // read in grade and increment corresponding grade counter depending on value
    while (inFS>> x >> y >> num) {
        if (num >= 90.0) { 
            aCount++; }
        else if (num >= 80.0) { 
            bCount++; }
        else if (num >= 70.0) { 
            cCount++; }
        else if (num >= 60.0)  { 
            dCount++; }
        else { 
            fCount++; }
    }

    // close file
    inFS.close();

    // print out count and grade
    cout << aCount << " A" << endl;
    cout << bCount << " B" << endl;
    cout << cCount << " C" << endl;
    cout << dCount << " D" << endl;
    cout << fCount << " F" << endl;

    // create csv file and input grades into it
    ofstream csvFile("statistics.csv");
    csvFile << "Grade,NumStudents" << endl;
    csvFile << "A," << aCount << endl;
    csvFile << "B," << bCount << endl;
    csvFile << "C," << cCount << endl;
    csvFile << "D," << dCount << endl;
    csvFile << "F," << fCount << endl;
    //close csv file
    csvFile.close();
    
}


