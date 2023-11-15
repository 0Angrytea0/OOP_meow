#include <iostream>
#include <string>

#include "figures.h"
#include "triangle.h"
#include "square.h"
#include "octagon.h"
#include "array.h"



int main(){
    // Triangle t1, t2, t3;
    // std::cin >> t1;
    // std::cin >> t2;
    // std::cout << t1 << std::endl;
    // std::cout << "Square:" << std::endl;
    // double sq = t1.square();
    // std::cout << sq << std::endl;
    // std::cout << t1.center() << std::endl;
    // t3 = t2;
    // std::cout << "Copied 1:" << endl;
    // std::cout << t3 << std::endl;
    // if (t1 == t2){
    //     std::cout << "Yes" << std::endl;
    // } else {
    //     std::cout << "Nope" << std::endl;
    // }
    // Square s1,s2,s3;
    // std::cin >> s1;
    // std::cin >> s2;
    // std::cout << s1 << std::endl;
    // s3 = s1;
    // std::cout << s3 << std::endl;
    // std::cout << s1.center() << endl;
    // std::cout << s1.square() << endl;
    // if (s1 == s2) {
    //     std::cout << "Yep" << std::endl;
    // } else {
    //     std::cout << "no";
    // }
    // Octagon o1, o2, o3;
    // std::cin >> o1;
    // std::cin >> o2;
    // std::cout << o1 << std::endl;
    // o3 = o1;
    // std::cout << o3 << std::endl;
    // std::cout << o1.center() << std::endl;
    // std::cout << o1.square() << std::endl;
    // if (o1 == o3)
    // {
    //     std::cout << "Yep" << std::endl;
    // } else {
    //     std::cout << "no";
    // }   

    Array arr;
    Triangle t;
    Octagon o;
    Square s;
    std::cin >> t;
    arr.push(&t);
    std::cout << arr[0]->center() << std::endl;
    std::cout << arr[0]->square() << std::endl;
    std::cout << t << std::endl;
    std::cin >> o;
    arr.push(&o);
    std::cout << arr[1]->center() << std::endl;
    std::cout << arr[1]->square() << std::endl;
    std::cout << o << std::endl;
    std::cin >> s;
    arr.push(&s);
    std::cout << arr[2]->center() << std::endl;
    std::cout << arr[2]->square() << std::endl;
    std::cout << s << std::endl;
    




}
