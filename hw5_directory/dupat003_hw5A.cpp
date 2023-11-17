// EE 1301 
// HW 5A
// Vennela Dupati
// dupat003

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const char BLANK = '-';
const char WALL = 'W';
const char ROBOT = 'X';
const char GOAL = 'O';
const int screen_num_lines = 25;
const int lengthX = 10;       // for now we only support square boards
const int lengthY = 10;       // it "should" work with non-square, YMMV
// Board is described by the following coordinate system:
// 0 --> +X
// |
// |
// V
// +Y

void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos);
void clearScreen();
void showGrid(char board[lengthX][lengthY]);

bool hasChar(char board[lengthX][lengthY], char findMe);
void updateGrid(char board[lengthX][lengthY], int &xPos, int &yPos, char action);

int main()
{
    char board[lengthX][lengthY] = {0};
    int xPos = 0, yPos = 0;

    // reads in mazeFile
    ifstream mazeFile("maze.txt");

    // checks if it exists and makes board
    if (mazeFile.is_open()) {
        for (int i = 0; i < lengthY; i++) {
            for (int j = 0; j < lengthX; j++) {
                mazeFile >> board[j][i];
                if (board[j][i] == ROBOT) {
                    xPos = j;
                    yPos = i;
                }
            }
        }
        mazeFile.close();
    } 
    // else just makes normal board
    else {
        initBoard(board, xPos, yPos);
    }

    while (hasChar(board, GOAL)) {
        char action;
        clearScreen();
        showGrid(board);
        cout << "Where would you like to go? (l, r, u, d) " << endl;
        cin >> action;

        updateGrid(board, xPos, yPos, action);
    }

    initBoard(board, xPos, yPos);

    clearScreen();
    showGrid(board);
    cout << "You found the cookie!  Congratulations!\n";

    return 0;
}

/*
Description: Initializes game board. Sets all characters in board as blanks,
then sets position of goal, and then sets position of robot.
Inputs:
    char board[][] - 2D array used to represent game board
    int xPos - saved x position of robot
    int yPos - saved y position of robot
Outputs: NA
*/
void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos) {
        for(int curRow=0; curRow < lengthY; curRow++) {
            for(int curCol=0; curCol < lengthX; curCol++) {
                board[curCol][curRow] = BLANK;
            }
        }

        board[0][0] = GOAL;
        board[lengthX/2][lengthY/2] = ROBOT;

        xPos = lengthX/2;
        yPos = lengthY/2;
}

/*
Description: Loops through given game board to determine if it contains given char findMe.
Inputs:
    char board[][] - 2D array used to represent game board
    char findMe - character to look for in game board
Outputs:
    bool - returns true if board contains findMe, else returns false 
*/
bool hasChar(char board[lengthX][lengthY], char findMe) {
    for(int curRow=0; curRow < lengthY; curRow++) {
        for(int curCol=0; curCol < lengthX; curCol++) {
            if(board[curCol][curRow] == findMe) {
                return true;
            }
        } //end curCol loop
    } // end curRow loop

    return false;
}

/*
Description: Prints out screen_num_lines amount of end lines to terminal so 
that old board is no longer visible.
Inputs: NA
Outputs: NA
*/
void clearScreen() {
    for(int i = 0;i<screen_num_lines;i++) {
        cout << endl;
    }
}

/*
Description: Prints out input game board to the terminal.
Inputs: 
    char board[][] - 2D array used to represent game board
Outputs: NA
*/
void showGrid(char board[lengthX][lengthY]) {
    for(int curRow=0; curRow < lengthY; curRow++) {
        for(int curCol=0; curCol < lengthX; curCol++) {
            cout << board[curCol][curRow];
        } // end curCol loop
        cout << endl;
    } // end curRow loop
}

/*
Description: Updates saved grid position of robot based on input action.
Inputs:
    char board[][] - 2D array used to represent game board
    int xPos - saved x position of robot
    int yPos - saved y position of robot
    char action - desired direction for robot to move, i.e. 'l', 'r', 'u', or 'd'
Outputs: NA
*/
void updateGrid(char board[lengthX][lengthY],int & xPos, int & yPos,char action) {
    int X = xPos;
    int Y = yPos;

    if (action == 'l' && xPos > 0) {
        X--;
    } else if (action == 'r' && xPos < lengthX - 1) {
        X++;
    } else if (action == 'u' && yPos > 0) {
        Y--;
    } else if (action == 'd' && yPos < lengthY - 1) {
        Y++;
    }

    // check if the target position is not a wall
    if (board[X][Y] != 'W') {
        board[xPos][yPos] = BLANK;
        xPos = X;
        yPos = Y;
        board[xPos][yPos] = ROBOT;
    }
}
