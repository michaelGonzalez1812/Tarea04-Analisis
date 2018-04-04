/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, TEC, Costa Rica
 *
 * This file is part of the CE3102 Numerical Analysis lecture at TEC
 *
 * @Author: 
 * @Date  : 24.02.2018
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "LUDoolittle.hpp"

/**
 * Herramienta para visualizar matrices
 * @tparam T
 * @param A
 */
template<typename T>
void printMatriz(anpi::Matrix<T> &A) {
    for (int unsigned i = 0; i < A.rows(); i++) {
        std::cout << "{ ";
        for (unsigned int j = 0; j < A.cols(); j++) {
            if (j == A.cols() - 1) std::cout << A[i][j];
            else std::cout << A[i][j] << ", ";
        }
        std::cout << " }" << std::endl;
    }
}

int main() {

    // Some example code
    anpi::Matrix<float> A = {{-1, -2, 1, 2},
                             {2,  0,  1, 2},
                             {-1, -1, 0, 1},
                             {1,  1,  1, 1}};
    anpi::Matrix<float> LU;
    std::vector<size_t> p;
    std::cout << "- LU Dolittle de A -" << std::endl;
    anpi::luDoolittle(A, LU, p);
    printMatriz(LU);
    std::cout << "- Unpack Dolittle de LU -" << std::endl;
    anpi::Matrix<float> L, U, LUA;
    anpi::unpackDoolittle(LU, L, U);
    std::cout << "L->" << std::endl;
    printMatriz(L);
    std::cout << "U->" << std::endl;
    printMatriz(U);
    std::cout << "- Comprobacion de A=L*U -" << std::endl;
    LUA = L * U;
    printMatriz(LUA);
    return EXIT_FAILURE;
}
