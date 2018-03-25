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
#include <algorithm>

#include "Exception.hpp"
#include "Matrix.hpp"

#ifndef ANPI_LU_DOOLITTLE_HPP
#define ANPI_LU_DOOLITTLE_HPP

namespace anpi {


  /**
   * Auxiliary method used to debug LU decomposition.
   *
   * It separates a packed LU matrix into the lower triangular matrix
   * L and the upper triangular matrix U, such that the diagonal of L
   * is composed by 1's.
   */
  template<typename T>
  void unpackDoolittle(const Matrix<T>& LU,
                       Matrix<T>& L,
                       Matrix<T>& U) {

    throw anpi::Exception("To be implemented yet");
  }
  
  /**
   * Decompose the matrix A into a lower triangular matrix L and an
   * upper triangular matrix U.  The matrices L and U are packed into
   * a single matrix LU. 
   *
   * The L matrix will have in the Doolittle's LU decomposition a
   * diagonal of 1's
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
  void luDoolittle(const Matrix<T>& A,
                   Matrix<T>& LU,
                   std::vector<size_t>& permut) {

    throw anpi::Exception("To be implemented yet");
  }

}
  
#endif

