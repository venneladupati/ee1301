#include <iostream>
using namespace std;
int main()
{
    int lecture;
    int lab;

    cout << "Input the number of students in the lecture: " << endl;
    cin >> lecture;
    cout << "Input the number of students per lab: " << endl;
    cin >> lab;

    cout << "The approximate ratio of lecture to sections is 1 to " << lecture/lab << endl;

    return 0;
}