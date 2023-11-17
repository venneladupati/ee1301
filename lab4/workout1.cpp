#include <iostream>
#include <stdlib.h>  
using namespace std;

void append(char first[], int firstLen, char sec[], int secLen, char result[]){
    for (int i=0;i< firstLen-1; i++) {
        result[i] = first[i];
    }

    for (int j=firstLen-1; j< secLen+firstLen; j++) {
        result[j] = sec[j-firstLen+1];
    }
}

int main(){
char first[] = "I am ";
char second[] = {'i', 'r', 'o', 'n', 'm', 'a', 'n', '\0'}; 
// Remember c-strings end in a '\0' (NULL) character, so the above 
// c-strings are 6 and 8 characters in length, respectively.
char result[200];
append(first, 6, second, 8, result); 
cout << result;

}