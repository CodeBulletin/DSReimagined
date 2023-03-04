#ifndef _DS_STATIC_ARRAY_H_
#define _DS_STATIC_ARRAY_H_

#include "Array.h"
#include <stdexcept>

template<class T, size_t e>
class StaticArray : public Array<T> {
private:
    int _m_array[e];
public:
    StaticArray() {
        if (e == 0) throw std::bad_alloc();
        this->m_size = e;
        this->m_array = _m_array;
    }
    // virtual bool sort() = 0;

};

#endif