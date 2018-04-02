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
#include <vector>
#include "LUDoolittle.hpp"
#include "Matrix.hpp"

//using namespace anpi;
int main() {


    anpi::Matrix<float> A = { {-1,-2,1,2},
                              { 2, 0,1,2},
                              {-1,-1,0,1},
                              { 1, 1,1,1} };
    anpi::Matrix<float> B = { {-1,-2,1,2},
                              { 2, 0,1,2},
                              {-1,-1,0,1}};
    anpi::Matrix<float> LU;
    anpi::Matrix<float> l=A*A;
    for(int unsigned i=0;i<l.rows();i++){
        for(unsigned int j=0;j<l.cols();j++){
            std::cout<<l[i][j]<<", ";
        }
        std::cout<<std::endl;
    }

    std::vector<float> t={1,2,3,4};

    std::vector<size_t> p;
    std::vector<float> k=A*t;
    for (unsigned int i=0;i<k.size();i++){
        std::cout<<k[i]<<", ";
    }

    //anpi::luDoolittle(A,LU,p);

    return EXIT_FAILURE;

}

//************************************************************
//Pruebas (NO BORRARLAS)
//*************************************************************

//std::vector<float> b = {1, 2, 3};
//std::cout<< b*b;