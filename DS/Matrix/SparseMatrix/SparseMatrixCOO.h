#ifndef _DS_SPARSE_MATRIX_COO_H_
#define _DS_SPARSE_MATRIX_COO_H_

#include "../SparseMatrix.h"

template<typename T>
class SparseMatrixCOO : public SparseMatrix<T> {
private:
    size_t m_non_zero = 0;
    size_t* m_row_indices;
    size_t* m_col_indices;
    T m_zero = 0;
    T* m_values;
    
public:
    SparseMatrixCOO(DenseMatrix<T> M) {
        for(int i = 0; i < M.getRows(); i++) {
            for(int j = 0; j < M.getCols(); j++) {
                if (M(i, j) != m_zero) m_non_zero++;
            }
        }
        this->m_rows = M.getRows(); 
        this->m_cols = M.getCols();
        this->m_row_indices = new size_t[m_non_zero];
        this->m_col_indices = new size_t[m_non_zero];
        this->m_values = new T[m_non_zero];
        int k = 0;
        for(int i = 0; i < M.getRows(); i++) {
            for(int j = 0; j < M.getCols(); j++) {
                if (M(i, j) != m_zero) {
                    m_row_indices[k] = i;
                    m_col_indices[k] = j;
                    m_values[k] = M(i, j);
                    k++;
                }
            }
        }
    }

    ~SparseMatrixCOO() {
        delete m_values;
        delete m_row_indices;
        delete m_col_indices;
    }

    T& operator() (size_t x, size_t y) {
        for(int i = 0; i < this->m_non_zero; i++) {
            if (this->m_row_indices[i] == x && this->m_col_indices[i] == y) {
                return m_values[i];
            }
        }
        return m_zero;
    }

    void operate(std::function<T(T)> fn) {
        for(int i = 0; i < this->m_non_zero; i++) {
            this->m_values = fn(this->m_values);
        }
    }

    void transpose() {
        std::swap(this->m_rows, this->m_cols);
        std::swap(this->m_row_indices, this->m_col_indices);
    }
};

#endif