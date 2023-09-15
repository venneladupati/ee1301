// C++ program to illustrate
// run-time error
#include <iostream>
using namespace std;

int main()
{
	int n = 9, div = 0;

	// wrong logic
	// number is divided by 0,
	// so this program abnormally terminates
	div = n/0;
	
    cout << "result = "<< div;
    return 0;
}

// This code is contributed by shivanisinghss2110 on https://www.geeksforgeeks.org/errors-in-cc/
