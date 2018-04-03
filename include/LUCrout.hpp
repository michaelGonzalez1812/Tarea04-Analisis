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
  void unpackCrout(const Matrix<T>& LU,
                   Matrix<T>& L,
                   Matrix<T>& U) {
      int n = LU.row();
      int j,i,k;
      // Creando matriz Lower
      for (i=0; i<n; i++) {
          for (j = 0; j < n; j++) {
              if (j < i) {
                  L[j][i] = 0;
              } else if (i == 0) {
                  L[j][i] = LU[j][i];
              } else {
                  for (k = 0; k < j; k++) {
                      L[j][i] = L[j][i] - L[j][k] * U[k][i];
                  }
              }
          }
          // Creando matriz Upper
          for (j = 0; j < n; j++) {
              if (j == i) {
                  U[j][i] = 1;
              } else if (j > i) {
                  U[j][i] = 0;
              } else if (j==0) {
                  U[j][i] = LU[j][i] / L[j][j];
              } else{
                  for (k = 0; k < j; k++) {
                      U[j][i] = U[j][i] - ((L[j][k] * U[k][i]) / L[j][j]);
                  }
              }

          }
      }

      std::cout << L << endln;
      std::cout << U << endln;

    throw anpi::Exception("To be implemented yet");

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
  void luCrout(const Matrix<T>& A,
               Matrix<T>& LU,
               std::vector<size_t>& permut) {

    throw anpi::Exception("To be implemented yet");
  }

}
  
#endif

