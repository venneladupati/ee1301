#include <iostream>
using namespace std;

int main() {

    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    
    int* fav1 = &array[3];
    int* fav2 = &array[7];
    int* fav3 = &array[6];

    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Vennela's favorite number: " << *fav1 << endl;
    cout << "Brock's favorite number: " << *fav2 << endl;
    cout << "Juliana's favorite number: " << *fav3 << endl;


    *fav2 = *fav1;

    cout << "Vennela's new favorite number: " << *fav1 << endl;
    cout << "Brock's new favorite number: " << *fav2 << endl;
    cout << "Juliana's new favorite number: " << *fav3 << endl;

    return 0;
}