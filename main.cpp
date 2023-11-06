// Вариант № 10
// Создать класс Twelve для работы с беззнаковыми целыми двенадцатиричными числами, 
// используя для представления числа массив из элементов типа unsigned char, 
// каждый из которых является двенадцатиричными цифрой. Младшая цифра имеет меньший индекс 
// (единицы – в нулевом элементе массива).

#include <iostream>
#include "lib.h"

int main()
{
        std::string s1,s2,s3;
        std::cout << "Enter strings:" << std::endl; 
        std::cin >> s1 >> s2;
        Twelve pn1(s1), pn2(s2);
        std::cout << "First string:" << std::endl; 
        pn1.print(std::cout) << std::endl;
        std::cout << "Second string:" << std::endl; 
        pn2.print(std::cout) << std::endl;
        if (pn1.greater(pn2))
        {
            std::cout << "First > second" << std::endl;
        } else if (pn1.less(pn2))
        {
            std::cout << "First < second" << std::endl;
        }
        Twelve copied1(pn1), copied2(pn2);
        std::cout << "Copied first string: " << std::endl; 
        copied1.print(std::cout) << std::endl;
        std::cout << "Copied second string: " << std::endl; 
        copied2.print(std::cout) << std::endl;
        try{
            Twelve pn12 = pn1.add(pn2);
            std::cout << "Sum:" << std::endl; 
            pn12.print(std::cout) << std::endl;

            Twelve pn13 = pn1.subtract(pn2);
            std::cout << "Dif:" << std::endl; 
            pn13.print(std::cout) << std::endl;
        }
        catch(std::exception &e){
            std::cerr << "exception: " << e.what() << std::endl;
        }
    return 0;
}