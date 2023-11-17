#include <iostream>
#include <stdlib.h>     
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])  {
        int i;


        cout << "You typed the following on the command-line:" << endl;

        if (argc < 3) {
                cout << argv[1][strlen(argv[1])-1] ;
            }

        else {
            cout << "Incorrect number of arguments! USAGE: swappy <string>";
            return 0;
        }

        for (i = 1; i < strlen(argv[1]) -1 ; i++) {
            cout << argv[1][i];
            }

        cout << argv[1][0] ;
       

        cout << endl;
}
