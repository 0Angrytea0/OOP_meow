#pragma once
#include <iostream>
#include <string>
#include "point.h"

class Figure
{
public:
    Figure() = default;
    Figure(std::string_view description): m_description(description){};

    virtual double square() const = 0;
    virtual Point center() const = 0;
    virtual operator double() const = 0;

    virtual ~Figure() = default;

protected:
    std::string m_description;
};