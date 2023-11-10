#pragma once

#include <iostream>
#include <string>

class Point
{
    friend bool operator==(const Point& left, const Point& right);
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
public:
    Point() = default;
	Point(double x, double y) : 
		m_x(x), m_y(y){
	}
    Point(const Point& other);
    
    // Point(const Point& other) : m_x(other.m_x), m_y(other.m_y) {}
	~Point() = default;

public:
    double m_x{};
    double m_y{};
};
