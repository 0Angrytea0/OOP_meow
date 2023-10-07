#include <iostream>
#include <string>

#include "lib.h"

using namespace std;


int main(){
    string line;
    cout << "Enter the expression ";
    getline(cin, line);
    cout << quantity_of_vowels(line) << endl;
    return 0;
}
