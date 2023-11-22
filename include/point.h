#pragma once

#include <iostream>
#include <string>

template <typename T>
concept _point = std::integral<T> || std::floating_point<T>;

template <_point T>
class Point
{
    template <_point F>
    friend bool operator==(const Point<F>& left, const Point<F>& right);
    template <_point F>
    friend std::istream& operator>>(std::istream& is, Point<F>& p);
    template <_point F>
    friend std::ostream& operator<<(std::ostream& os, const Point<F>& p);
public:
    Point() = default;
	Point(T x, T y) : 
		_x(x), _y(y){
	}
    Point(const Point<T>& other);
	~Point() = default;

public:
    double _x{};
    double _y{};
};
