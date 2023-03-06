#ifndef _DS_STATIC_ARRAY_H_
#define _DS_STATIC_ARRAY_H_

#include "Array.h"
#include <stdexcept>

template<class T, size_t max_size>
class StaticArray : public Array<T> {
private:
    T _m_array[max_size];
public:
    StaticArray(bool x = true, size_t size = 0) {
        if (max_size == 0) throw std::bad_alloc();
        this->m_size = x ? max_size : size;
        this->m_array = _m_array;
    }

    void push(T obj) {
        if (this->m_size == max_size) throw std::out_of_range("Array is full");
        this->m_array[this->m_size++] = obj;
    }

    void resize(size_t size) {
        if (size > max_size) throw std::out_of_range("Can't Resize more than capacity");
        this->m_size = size;
    }

};

#endif