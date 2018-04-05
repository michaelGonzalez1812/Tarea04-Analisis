#include <cmath>
#include <limits>
#include <functional>

#include "Exception.hpp"
#include "Matrix.hpp"


namespace anpi {

    /**
     *
     * @tparam T
     * @param A Matriz
     * @return Transpuesta de la Matriz A
     */
    template<typename T>
    Matrix<T>ftranspuesta(const Matrix<T> &A) {
       Matrix<T>AT(A.cols(),A.rows());
        for (int i = 0; i < A.rows(); i++) {
            for (int j = 0; j < A.cols(); j++) {
                AT[i][j] = A[j][i];
            }
        }
        return X;
    }
    /**
     *
     * @tparam T
     * @param size entero tamano de la matriz
     * @return Matriz identidad
     */

    template<typename T>
    Matrix<T>fidentidad(int size) {
        Matrix<T>result(size, size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == j) {
                    result[i][j] = 1;
                } else {
                    result[i][j] = 0;
                }
            }
        }
        return result;
    }
    /**
     * @tparam T
     * @param A Matriz
     * @param fila numero de fila
     * @return vector fila
     */

    template <typename T>
    Matrix<T>fila(const Matrix<T>&A,int fila){
        Matrix<T>result(1,A.cols());
        for(int j=0;j<A.cols();++j){
            result[0][j]=A[fila][j];
        }
        return result;
    }
    /**
     * @tparam T
     * @param A Matriz
     * @param fila numero de fila
     * @param columna numero de columna
     * @return cofactor del elemento en la posicion
     */
    template <typename T>
    T cofactor (Matrix<T>&A, T fila, T columna){
        Matrix<T>tempMatriz(A.rows()-1,A.cols()-1,Matrix<double>::DoNotInitialize);
        int x=0;
        int y=0;
        for(int i=0;i<A.rows();++i){
            for(int j=0;j<A.cols();++j){
                if (i != fila && j != columna){
                    tempMatriz[x][y]=A[i][j];
                    y=y+1;
                    if (y>=tempMatriz.cols()){
                        x=x+1;
                        y=0;
                    }
                }
            }
        }
        T temp = determinante(tempMatriz);
        return(pow(-1,fila+columna))*tem;
    }
    /**
     *
     * @tparam T
     * @param data valor x a multiplicar
     * @param B Matriz
     * @return Multiplicaion de x por cada elemento de la matriz
     */
    template<typename T>
    Matrix<T> multiplicadorx (T data,anpi::Matrix<T> B){
        Matrix<T> result(B.rows(),B.cols());
        for(int i=0;i<B.rows(); ++i){
            for(int j=0; j<B.cols();++j){
                result[i][j]= B[i][j]*data;
            }}
        return result;
    }
    /**
     * INCOMPLETO
     * @tparam T
     * @param A Matriz A
     * @param Q Matriz Q
     * @param R Matriz R
     */
    template<typename T>
    void qr(const Matrix<T> &A, Matrix<T> &Q, Matrix<T> &R) {
        //implementacion de qr
          }

}


