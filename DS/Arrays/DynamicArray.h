#ifndef _DS_DYNAMIC_ARRAY_H_
#define _DS_DYNAMIC_ARRAY_H_

#include "Array.h"
#include <stdexcept>

template<class T>
class DynamicArray : public Array<T> {
private:
    size_t m_bucket_size;
    float m_bucket_multiplier;
public:
    DynamicArray(size_t size = 0, float bucket_multiplier = 2.0) {
        this->m_bucket_size = size == 0 ? 1 : size;
        if ((size_t)(bucket_multiplier * this->m_bucket_size) == this->m_bucket_size) throw std::bad_alloc();
        this->m_bucket_multiplier = bucket_multiplier;
        this->m_size = size;
        this->m_array = new T[this->m_bucket_size];
    }

    ~DynamicArray() {
        delete this->m_array;
    }

    void push(T obj) {
        if (this->m_size == this->m_bucket_size) {
            resize((size_t)(this->m_bucket_multiplier * this->m_bucket_size));
        }
        this->m_array[this->m_size] = obj;
        this->m_size++;
    }

    void resize(size_t size) {
        T* temp = new T[size];
        for(size_t i = 0; i < std::min(size, this->m_bucket_size); i++) {
            temp[i] = this->m_array[i];
        }
        this->m_bucket_size = size == 0 ? 1 : size;
        if (size < this->m_size) this->m_size = size;
        delete this->m_array;
        this->m_array = temp;
    }
};

#endif