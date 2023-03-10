#include <iostream>
#include "DS/Matrix/DenseMatrix.h"
#include "DS/Matrix/SparseMatrix/SparseMatrixCOO.h"

int sum(int x, int y) {
    return x + y;
}

int main() {
    DenseMatrix<int> matrix1(5, 5);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            matrix1(i, j) = rand() % 6 < 4 ? 0 : i * 5 + j;
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            std::cout << matrix1(i, j) << "\t";
        }
        std::cout << std::endl;
    }
    
    SparseMatrixCOO<int> matrix(matrix1);
    matrix.transpose();
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout << matrix(i, j) << "\t";
        }
        std::cout << std::endl;
    }
}