#include "point.h"

template <_point T>
Point<T>::Point(const Point<T>& other) : _x(other._x), _y(other._y) {}

template <_point T>
bool operator==(const Point<T>& left, const Point<T>& right){
    return (left._x == right._x) && (left._y == right._y);
}

template <_point T>
std::istream& operator>>(std::istream& is, Point<T>& p){
    double x,y;
    std::cout << "Enter 'x' and 'y' :" << std::endl;
    is >> x >> y;
    p._x = x;
    p._y = y;
    return is;
}

template <_point T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p){
    os << "(x: " << p._x << "; y: " << p._y << ")";
    return os;
}