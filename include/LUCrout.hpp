/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * This file is part of the numerical analysis lecture CE3102 at TEC
 *
 * @Author: 
 * @Date  : 03.03.2018
 */

#include <cmath>
#include <limits>
#include <functional>

#include "Exception.hpp"
#include "Matrix.hpp"

#ifndef ANPI_LU_CROUT_HPP
#define ANPI_LU_CROUT_HPP

namespace anpi {

    /**
     * Auxiliary method used to debug LU decomposition.
     *
     * It separates a packed LU matrix into the lower triangular matrix
     * L and the upper triangular matrix U, such that the diagonal of U
     * is composed by 1's.
     */
    template<typename T>
    void unpackCrout(const Matrix <T> &LU,
                     Matrix <T> &L,
                     Matrix <T> &U) {
        if (LU.rows() == LU.cols()) {
            L = LU;
            U = LU;
            for (unsigned int i = 0; i < LU.rows(); i++) {
                for (unsigned int j = 0; j < LU.rows(); j++) {
                    if (i == j) { // diagonal
                        U[i][j] = T(1);
                        L[i][j] = LU[i][j];
                    } else if (i > j) { // matriz triangular inferior
                        U[i][j] = T(0);
                        L[i][j] = LU[i][j];
                    } else { // matriz triangular superior
                        L[i][j] = T(0);
                        U[i][j] = LU[i][j];
                    }
                }
            }
        } else throw anpi::Exception("La matriz no es cuadrada");
    }

    /**
     * Decompose the matrix A into a lower triangular matrix L and an
     * upper triangular matrix U.  The matrices L and U are packed into
     * a single matrix LU.
     *
     * Crout's way of packing assumes a diagonal of
     * 1's in the U matrix.
     *
     * @param[in] A a square matrix
     * @param[out] LU matrix encoding the L and U matrices
     * @param[out] permut permutation vector, holding the indices of the
     *             original matrix falling into the corresponding element.
     *             For example if permut[5]==3 holds, then the fifth row
     *             of the LU decomposition in fact is dealing with the third
     *             row of the original matrix.
     *
     * @throws anpi::Exception if matrix cannot be decomposed, or input
     *         matrix is not square.
     */
    template<typename T>
    void luCrout(const Matrix <T> &A,
                 Matrix <T> &LU,
                 std::vector<size_t> &permut) {
        //transpuesta
        if (A.rows() == A.cols()) {
            LU = A;
            for (unsigned int i = 0; i < A.rows(); i++) {
                for (unsigned int j = 0; j < A.rows(); j++) {
                    LU[j][i] = A[i][j]; // filas por columnas
                }
            }

            T cte = T(0); // constante para generar ceros de la triagular superior
            for (unsigned int k = 0; k < A.rows() - 1; k++) {
                for (unsigned int i = k + 1; i < A.rows(); i++) {
                    for (unsigned int j = k; j < A.rows(); j++) {
                        if (LU[k][k] != 0) {
                            if (j == k) {
                                cte = LU[i][k] / LU[k][k];
                                LU[i][j] = cte; //calculo el L
                            } else {
                                LU[i][j] = LU[i][j] - cte * LU[k][j]; //calculo U
                            }

                        }

                    }

                }

            }

            Matrix<T> LUtemp = LU;
            for (unsigned int i = 0; i < A.rows(); i++) {
                for (unsigned int j = 0; j < A.rows(); j++) {
                    LU[j][i] = LUtemp[i][j];
                }
            }
        } else throw anpi::Exception("La matriz no es cuadrada");
    }

}

#endif

