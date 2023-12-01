#pragma once
#include "allocator.h"

template <class T, size_t N, class Allocator_ = Allocator<T>>
class Container{
public:
    using value_type = T;
    using allocator_type = Allocator_;

    Container() : data(allocator_type().allocate(N)), size(0), capacity(N) {}

    void push_back(const T& value) { 
        if (size == capacity) { 
            T* n_data = allocator_type().allocate(capacity + 1); 
            for (size_t i = 0; i < size; ++i) { 
                n_data[i] = data[i];
            }
            allocator_type().deallocate(data, capacity); 
            data = n_data; 
            capacity += 1; 
        }
        data[size++] = value; 
    }

    //для константных объектов можно вызывать только константные функции
    void print() const {
        for (size_t i = 0; i < size; ++i) { 
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    T* data; //данные
    size_t size; //занятость
    size_t capacity; //вместимость
};