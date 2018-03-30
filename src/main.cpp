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
#include <iterator>
#include "LUDoolittle.hpp"
#include "Matrix.hpp"

//using namespace anpi;
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

//************************************************************
//Pruebas (NO BORRARLAS)
//*************************************************************

//std::vector<float> b = {1, 2, 3};
//std::cout<< b*b;