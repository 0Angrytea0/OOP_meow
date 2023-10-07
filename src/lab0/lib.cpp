// Copyright 2023 SomeName

#include <iostream>
#include <string>
using namespace std;

#include "lib.h"

int quantity_of_vowels(string line){
    int i = 0;
    string vowels = "aeouyi";
    int quantity = 0; 
    while (i < line.length()){
        for (int l = 0; l < vowels.length(); l++){
            if (line[i] == vowels[l]){
                quantity++;
            }
        }
        i++;
    }
    return quantity;
}
