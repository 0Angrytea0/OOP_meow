// Copyright 2023 SomeName

#include <iostream>
#include <string>
using namespace std;

#include "lib.h"

int quantity_of_vowels(int quantity, string line, char vowels[]){
    int i = 0;
    while (i < line.length()){
        for (int l = 0; l < 6; l++){
            if (line[i] == vowels[l]){
                k++;
            }
        }
        i++;
    }
    return quantity;
}
