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

#include "LUDoolittle.hpp"

int main() {

  // Some example code
  anpi::Matrix<float> A = { {-1,-2,1,2},
                            { 2, 0,1,2},
                            {-1,-1,0,1},
                            { 1, 1,1,1} };
  anpi::Matrix<float> LU;

  std::vector<size_t> p;
  anpi::luDoolittle(A,LU,p);

  return 0;
}
  
