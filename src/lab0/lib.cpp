// Copyright 2023 SomeName

#include <iostream>
#include <string>
using namespace std;

#include "lib.h"

int kolvo(int k, string line, char vowel[]){
    int i = 0;
    while (i < line.length()){
        for (int l = 0; l < 6; l++){
            if (line[i] == vowel[l]){
                k++;
                cout << k << " " << line[i] << endl;
            }
        }
        i++;
    }
    return k;
}