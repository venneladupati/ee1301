#include <iostream>
#include <stdlib.h>  
using namespace std;

void append(char first[], char sec[], char result[]){
    int i = 0;
    while (first[i] != '\0') {
        result[i] = first[i];
        i++;
    }

    int j = 0;
    while (sec[j] != '\0'){
        result[i] = sec[j];
        i++;
        j++;
    }

    result[i] = '\0';
}

int main(){
char first[] = "I am ";
char second[] = {'i', 'r', 'o', 'n', 'm', 'a', 'n','\0'}; 
// Remember c-strings end in a '\0' (NULL) character, so the above 
// c-strings are 6 and 8 characters in length, respectively.
char result[200];
append(first, second, result); 
cout << result;

}