// EE 1301
// HW 6A
// Vennela Dupati
// dupat003

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ARRAY_SIZE = 1000;

int binarySearch(const int sortedArray[], int numVal, int leftBound, int rightBound);

int main() {
    //declare variables
    int sortedArray[MAX_ARRAY_SIZE];
    int arraySize = 0;
    
    // Ask the user for the filename
    cout << "What is the file with the array you want to search? ";
    string filename;
    cin >> filename;

    // Read the array from the file
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening file. Exiting." << endl;
        return 1;
    }

    while (inputFile >> sortedArray[arraySize]) {
        arraySize++;
    }

    // Ask the user for the number to find
    int numVal;
    cout << "What is the number you want to find? Please provide an integer: ";
    cin >> numVal;

    // Perform binary search
    int index = binarySearch(sortedArray, numVal, 0, arraySize - 1);

    // Output the result
    if (index != -1) {
        cout << numVal << " can be found at sortedArray[" << index << "]" << endl;
    } else {
        cout << numVal << " is not in sortedArray." << endl;
    }

    return 0;
}

int binarySearch(const int sortedArray[], int numVal, int leftBound, int rightBound) {
    if (leftBound > rightBound) {
        // Base case: element not found
        return -1;
    }

    int mid = (leftBound + rightBound) / 2;

    if (sortedArray[mid] == numVal) {
        // Base case: element found
        return mid;
    } else if (sortedArray[mid] > numVal) {
        // Recursive case: search in the left half
        return binarySearch(sortedArray, numVal, leftBound, mid - 1);
    } else {
        // Recursive case: search in the right half
        return binarySearch(sortedArray, numVal, mid + 1, rightBound);
    }
}