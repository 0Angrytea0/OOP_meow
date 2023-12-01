#pragma once
#include <iostream>
#include <map>
#include <stdlib.h>

template <class T>
class Allocator{
public:
    using value_type = T;

    Allocator() = default;

    template<class U>
    Allocator(const Allocator<U>&){}

    T* allocate(size_t n){
        auto ptr = static_cast<T*>(::operator new(n * sizeof(T)));
        if (ptr) return ptr;
        throw std::bad_alloc();
    }

    void deallocate(T* ptr, size_t n){
        free(ptr);
    }
};