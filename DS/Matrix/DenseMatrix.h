#ifndef _DS_DENSE_MATRIX_H_
#define _DS_DENSE_MATRIX_H_

#include "./Matrix.h"
#include <functional>

template <typename T>
class DenseMatrix : public Matrix<T> {
protected:
    T* m_array;
    size_t getIndex(size_t x, size_t y) const {
        return x * this->m_cols + y;
    }

public:
    DenseMatrix(size_t rows, size_t cols) {
        if (rows == 0 || cols == 0) throw std::invalid_argument("row or size can't be zero");
        this->m_rows = rows;
        this->m_cols = cols;
        this->m_array = new T[rows * cols];
    }

    ~DenseMatrix() {
        delete this->m_array;
    }

    T& operator()(size_t x, size_t y) {
        return this->m_array[this->getIndex(x, y)];
    }

    T& operator[](size_t idx) {
        return this->m_array[idx];
    }

    void operate(std::function<T(T)> fn) {
        for(int i = 0; i < this->m_rows * this->m_cols; i++) {
            this->m_array[i] = fn(this->m_array[i]);
        }
    }

    static DenseMatrix<T> operate(DenseMatrix<T>& a1, DenseMatrix<T>& a2, std::function<T(T, T)> fn) {
        if (a1.getCols() != a2.getCols() || a1.getRows() != a2.getRows())
            throw std::domain_error("Cols or rows on't match");
        DenseMatrix<T> a(a1.getRows(), a1.getCols());
        for(int i = 0; i < a.getCols() * a.getRows(); i++) {
            a[i] = a1[i] + a2[i];
        }
        return a;
    }

    static DenseMatrix<T> mul(DenseMatrix<T>& a1, DenseMatrix<T>& a2) {
        if(a1.getCols() != a2.getRows())
            throw std::domain_error("M1 col does not match with M2 row");
        
        DenseMatrix<T> a(a1.getRows(), a2.getCols());
        for(int i = 0; i < a1.getRows(); i++) {
            for(int j = 0; j < a2.getCols(); j++) {
                a(i, j) = 0;
                for(int k =0; k < a2.getCols(); k++) {
                    a(i, j) += a1(i, k) * a2(k, j);
                }
            }
        }
        return a;
    }
};

#endif