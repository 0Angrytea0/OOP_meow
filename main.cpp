#include <iostream>
#include <string>

#include "lib.h"

using namespace std;


int main(){
    char vowel[] = {'a', 'e', 'i', 'o', 'y', 'u'};
    int k = 0; 
    string line;
    getline(cin, line);
    cout << kolvo(k, line, vowel) << endl;
    return 0;
}