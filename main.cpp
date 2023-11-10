//6угольник 8угольник треугольник
/*

в каждой фигуре написать вычисление геометр. центра, площади
переместить, задав направление (x,y) и на сколько
Как сравнить? 
*/

#include <iostream>
#include <string>

#include "figures.h"
#include "triangle.h"

using namespace std;


int main(){
    Triangle t1, t2, t3;
    std::cin >> t1 >> t2;
    std::cout << t1 << std::endl;
    std::cout << t1.square() << std::endl;
    std::cout << t1.center() << std::endl;
    t3 = t2;
    std::cout << t3 << std::endl;
    if (t1 == t2){
        std::cout << "Yes" << std::endl;
    }

}
