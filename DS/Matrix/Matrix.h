#ifndef _DS_MATRIX_H_
#define _DS_MATRIX_H_

#include <stdexcept>
#include <functional>

template <typename T>
class Matrix {
protected:
    size_t m_rows;
    size_t m_cols;

public:
    size_t getRows() const {
        return m_rows;
    }

    size_t getCols() const {
        return m_cols;
    }

    virtual T& operator()(size_t x, size_t y) = 0;
};

#endif