// EE 1301 
// HW 5C
// Vennela Dupati
// dupat003

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int MAX_N = 100;

// Function to perform the averaging process on the input array
void averagePixels(int inputArray[MAX_N][MAX_N], int outputArray[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            int count = 0;

            // Check neighboring pixels
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int ni = i + x;
                    int nj = j + y;

                    if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                        sum += inputArray[ni][nj];
                        count++;
                    }
                }
            }

            // Calculate the average and store it in the output array
            outputArray[i][j] = sum / count;
        }
    }
}

int main(int argc, char* argv[]) {

    int inputArray[MAX_N][MAX_N];
    int outputArray[MAX_N][MAX_N];
    int N;

    // Read the input from the file
    ifstream inputFile(argv[1]);
    inputFile >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inputFile >> inputArray[i][j];
        }
    }
    inputFile.close();

    // Perform the averaging process
    averagePixels(inputArray, outputArray, N);

    // Print the resulting  values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << outputArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}