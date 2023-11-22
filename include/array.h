#pragma once
#include <concepts>
#include <memory>
#include <iostream>
#include "figures.h"

template <class T>
concept Arrayable = std::is_default_constructible<T>::value;

template <Arrayable T>
class Array
{
public:
    Array();
    void resize(size_t new_size);
    void push(T fig);
    T& operator[](size_t index);
    void remove(size_t index);
    size_t size();
    ~Array() noexcept {};

private:
    size_t _size;
    std::shared_ptr<T[]> arr;
};