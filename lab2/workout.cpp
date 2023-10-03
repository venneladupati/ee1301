// EE1301
// Lab 2 Workout
// Vennela Dupati
// dupat003

#include <iostream>
using namespace std;
int main(){
	int F0, F1, FN, F_Nm1, F_Nm2;
	int N; // the index of the last Fibonacci number
	cout << "Enter the value for F0 and F1:\n";
	cin >> F0 >> F1; // read two inputs from the terminal  
	cout << "Enter last Fibonacci numbers you want FN (Enter N):\n";
    cin >> N; // read the index N from the terminal

    F_Nm1 = F1;   // update F_(N-1) for first loop
    F_Nm2 = F0;   // update F_(N-2) ...
  
 for (int i = 2; i <= N; i=i+1 ){   
		FN = F_Nm1 + F_Nm2; // represent the next Fibonacci number with F0 and F1
		cout << "F" << i << "="<<"F"<<i-1 << "+"<<"F" << i-2 << "=" << F_Nm1 << "+" << F_Nm2 << "=" << FN<< endl; // print out the Fibonacci number in the required way
		F_Nm2 = F_Nm1; // update F_(N-2) for next loop
		F_Nm1 = FN; // update F_(N-1) ...
 }
	return 0;
 }
