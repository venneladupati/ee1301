// EE 1301
// HW 6A
// Vennela Dupati
// dupat003

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

const int MAX_NUM_DICE = 50;

void userInputParser(string s, int dice[], int maxNumDie);

class Dice {
private:
    int minRoll;
    int maxRoll;

public:
    // Default constructor
    Dice() : minRoll(1), maxRoll(6) {}

    // Constructor with custom min and max values
    Dice(int min, int max) : minRoll(min), maxRoll(max) {}

    // Roll function
    int roll() const {
        return rand() % (maxRoll - minRoll + 1) + minRoll;
    }
};

int main() {
    int pairs[2 * MAX_NUM_DICE + 1] = {0};
    srand(time(0)); // DO NOT WRITE THIS LINE AGAIN OR ANYWHERE ELSE
    cout << "What die do you want to roll? (e.g. 4d3+2) ";
    string s;
    getline(cin, s);
    userInputParser(s, pairs, MAX_NUM_DICE);

    // Get the number of rounds
    int numRounds;
    cout << "How many rounds do you want to roll? ";
    cin >> numRounds;

    // Create an array of Dice objects based on user input
    Dice* diceObjects = new Dice[pairs[0] / 2];

    // Roll the dice for the specified number of rounds
    int totalSum = 0;
    int minRoll = INT_MAX;
    int maxRoll = INT_MIN;


        cout << "Sample Roll: ";
        int roundSum = 0;

        // Roll each die and display the sample roll
        for (int i = 1; i < pairs[0]; i += 2) {
            int roll = diceObjects[i / 2].roll();
            roundSum += roll;
        }
        cout << roundSum << endl;


    for (int round = 1; round <= numRounds; ++round) {
        roundSum = 0;

        // Roll each die and display the sample roll
        for (int i = 1; i < pairs[0]; i += 2) {
            int roll = diceObjects[i / 2].roll();
            roundSum += roll;
        }


        // Update min and max values
        minRoll = min(minRoll, roundSum);
        maxRoll = max(maxRoll, roundSum);
        totalSum += roundSum;
    }

    // Calculate average
    double average = static_cast<double>(totalSum) / numRounds;

    // Display results
    cout << "Minimum Roll: " << minRoll << "\nMaximum Roll: " << maxRoll
         << "\nAverage Value: " << average << endl;

    // Clean up dynamically allocated memory
    delete[] diceObjects;

    return 0;
}

void userInputParser(string s, int dice[], int maxNumDie) {
    string data[4 * maxNumDie];

    int parts = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'd' || s[i] == '+') {
            parts++;
        }
    }

    int index = 0;
    unsigned d = s.find('d');
    unsigned p = s.find('+');
    while (d != static_cast<unsigned>(-1) || p != static_cast<unsigned>(-1)) {
        bool dFirst = d < p;
        if (dFirst) {
            string before = s.substr(0, d);
            int count = 0;
            bool foundDigit = false;
            for (int i = 0; i < static_cast<signed>(s.length() - d - 1); i++) {
                if (isdigit(s[count + d + 1])) {
                    foundDigit = true;
                }
                if (!isdigit(s[count + d + 1]) && foundDigit) {
                    break;
                }
                count++;
            }
            string after = s.substr(d + 1, count);

            data[index] = before;
            data[index + 1] = after;
            index += 2;

            s = s.substr(d + count + 1);
        } else {
            int count = 0;
            bool foundDigit = false;
            for (int i = 0; i < static_cast<signed>(s.length() - p - 1); i++) {
                if (isdigit(s[count + p + 1])) {
                    foundDigit = true;
                }
                if (!isdigit(s[count + p + 1]) && foundDigit) {
                    break;
                }
                count++;
            }
            string after = s.substr(p + 1, count);

            data[index] = "+";
            data[index + 1] = after;
            index += 2;

            s = s.substr(p + count + 1);
        }

        d = s.find('d');
        p = s.find('+');
    }

    int diceCount = 0;
    for (int i = 0; i < parts * 2; i += 2) {
        if (data[i][0] == '+') {
            diceCount++;
        } else {
            diceCount += atoi(data[i].c_str());
        }
    }

    dice[0] = diceCount * 2 + 1;

    int ind = 1;
    for (int i = 0; i < parts * 2; i += 2) {
        if (data[i][0] == '+') {
            dice[ind] = atoi(data[i + 1].c_str());
            dice[ind + 1] = atoi(data[i + 1].c_str());

            ind += 2;
        } else {
            for (int j = 0; j < atoi(data[i].c_str()); j++) {
                dice[ind] = 1;
                dice[ind + 1] = atoi(data[i + 1].c_str());

                ind += 2;
            }
        }
    }
}


