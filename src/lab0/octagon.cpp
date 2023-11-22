#include "octagon.h"
#include <math.h>

template <Number T>
Octagon<T>::Octagon(Point<T>& ver1, Point<T>& ver2, Point<T>& ver3, Point<T>& ver4, Point<T>& ver5, Point<T>& ver6, Point<T>& ver7, Point<T>& ver8)
{
    Point<T> ver[size] = {ver1, ver2, ver3, ver4, ver5, ver6, ver7, ver8};
    for (size_t i = 0; i < size; ++i)
    {
        oct[i] = ver[i];
    }
}

template <Number T>
Octagon<T>::Octagon(const Octagon<T>& other)
{
    size = other.size;
    for (size_t i = 0; i < size; ++i)
    {
        oct[i] = other.oct[i];
    }
    
}

template <Number T>
Point<T> Octagon<T>::center() const
{
    T sr_x = 0, sr_y = 0;
    for (size_t i = 0; i < size; ++i){
        sr_x += oct[i]._x;
        sr_y += oct[i]._y;
    }
    return Point<T>(sr_x / 8.0, sr_y / 8.0);
}

template <Number T>
T Octagon<T>::square() const 
{
    T x1 = oct[0]._x; T y1 = oct[0]._y;
    Point<T> center = this->center();
    T R = sqrt(pow((x1 - center._x),2) + pow((y1 - center._y),2));
    T r = R * cos(M_PI / size);
    T area = 0.5 * size * R * r;
    return area;
}

template <Number T>
Octagon<T>& Octagon<T>::operator=(const Octagon<T>& other)
{
    if (this != &other)
    {
        for (size_t i{0}; i < size; ++i)
        {
            oct[i] = other.oct[i];
        }
    }
    return *this;
}

template <Number T>
Octagon<T>& Octagon<T>::operator=(Octagon<T>&& other)
{
    if (this != &other)
    {
        for (size_t i{0}; i < size; ++i)
        {
            oct[i] = std::move(other.oct[i]);
        }
    }
    return *this;
}

template <Number T>
void sort_o(T length_oct[]){
    size_t quantity_of_side = 8;
    for (size_t i = 0; i < quantity_of_side; ++i)
    {
        for (size_t j = 0; j < quantity_of_side; ++j)
        {
            if (length_oct[i] > length_oct[j]) {
                T x = length_oct[i]; 
                length_oct[i] = length_oct[j];
                length_oct[j] = x;
            }
        }
    }
}

template <Number T>
bool Octagon<T>::operator==(const Octagon<T>& other)
{
    size_t quantity_of_lines = 8;
    T length_oct1[quantity_of_lines]{};
    T length_oct2[quantity_of_lines]{};
    for (size_t i = 0; i < quantity_of_lines; ++i)
    {
        for (size_t j = i + 1; j < quantity_of_lines; ++j)
        {
            length_oct1[i] = sqrt((pow((oct[i]._x - oct[j]._x),2) + pow((oct[i]._y - oct[j]._y),2)));
            length_oct2[i] = sqrt((pow((other.oct[i]._x - other.oct[j]._x),2) + pow((other.oct[i]._y - other.oct[j]._y),2)));
        }
    }
    sort_o(length_oct1);
    sort_o(length_oct2);
    int count = 0;
    for (size_t i = 0; i < quantity_of_lines; ++i)
    {
        if (length_oct1[i] == length_oct2[i])
        {
            count++;
        }
    }
    if (count == quantity_of_lines) return true;
    return false;
}

template <Number T>
Octagon<T>::operator double() const
{
    return square();
}
