#include <iostream>
#include <string>

#include "lib.h"

using namespace std;


int main(){
    char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
    int quantity = 0; 
    string line;
    cout << "Enter the expression ";
    getline(cin, line);
    cout << quantity_of_vowels(quantity, line, vowels) << endl;
    return 0;
}
