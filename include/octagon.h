#pragma once

#include <iostream>
#include <string>
#include "figures.h"

template <Number T>
class Octagon: public Figure<T>
{
    template <Number F>
    friend std::ostream& operator<<(std::ostream& os, const Octagon<F>& t);
    template <Number F>
    friend std::istream& operator>>(std::istream& is, Octagon<F>& t);
public:
    Octagon(): oct{Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>()}{};
    Octagon(Point<T>& ver1, Point<T>& ver2, Point<T>& ver3, Point<T>& ver4, Point<T>& ver5, Point<T>& ver6, Point<T>& ver7, Point<T>& ver8);
    Octagon(const Octagon<T> &other);

    virtual T square() const override;
    virtual Point<T> center() const override;
    Octagon<T>& operator=(const Octagon<T>& other);
    Octagon<T>& operator=(Octagon<T>&& other);
    bool operator==(const Octagon<T>& other);
    virtual operator double() const;

    ~Octagon(){};

    Point<T> oct[8]{};
    size_t size{8};
};

template <Number T>
inline std::ostream& operator<<(std::ostream& os, const Octagon<T>& f){
    os << "Octagon's coordinates:"<< std::endl;
    for(size_t i = 0; i < f.size; ++i){
        os << f.oct[i] << std::endl;
    }
    return os;
}

template <Number T>
inline std::istream& operator>>(std::istream& is, Octagon<T>& f){
    std::cout << "Please enter the coordinates of the vertices of the octagon:" << std::endl;
    std::cout << "order [x,y], separated by spaces" << std::endl;
    for (size_t i = 0; i < f.size; ++i) {
        is >> f.oct[i];
        if (is.fail()) {
            throw std::invalid_argument("Input must be a number");
        }
    }
    for (int i = 0; i < f.size; i++) {
        for (int j = i + 1; j < f.size; j++) {
            if (f.oct[i] == f.oct[j]) {
                throw std::logic_error("Same coordinates for different point<T>s");
            }
        }
    }
    return is;
}
