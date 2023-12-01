#include "allocator.h"
#include "container.h"

#include <iostream>
#include <map>

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main() {
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> Map;
    for (size_t i{0}; i < 10; ++i){
        Map[i] = factorial(i);
    }
    for (const auto& pair : Map) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    Container<int, 5> _Container;
    for (int i{0}; i < 10; ++i){
        _Container.push_back(i);
    }
    _Container.print();
}
