#pragma once

#include <vector>
#include <initializer_list>
#include <iostream>

/** 
 * Matrix class
 * 
 * Description: 
 *  Defines the core Matrix object of LinAlg. This object should be optimized to act as both a vector and a multidimensional matrix
 * 
*/
namespace linalg {
    template<class dtype>
    class Matrix {
        using self_type = Matrix<dtype>;
        using vec_type = std::vector<dtype>;
        using mat_type = std::vector<std::vector<dtype>>;
        private:
            /// Class properties
            /// int row and column dimensions of the Matrix object
            int row_dim;
            int col_dim;
            /// std::vector object containing a 2D Matrix
            mat_type data;
            /// std::vector object containing a 1D vectpr
            vec_type vector_data;

            /// Bolean properties
            /// is the Martix object a 1D vector
            bool isVector;

        public:
            /// Constructors
            /// Default constructor
            Matrix() : row_dim(1), col_dim(1), isVector(true), vector_data(vec_type(1, 0)) {}
            /// Single dim Matrix (vector)
            Matrix(int dim) : isVector(true), row_dim(1), col_dim(dim), vector_data(vec_type(dim, 0)) {}
            /// 2-dim Matrix
            Matrix(int rows, int cols) : row_dim(rows), col_dim(cols), isVector(false) {
                // Initialze data with 2D std::vector of size rows x cols filled with 0's
                data = mat_type(row_dim, vec_type(col_dim));
            }
            /// Custom 1d input Matrix (vector)
            Matrix(std::initializer_list<dtype> list) : row_dim(1), col_dim(list.size()), isVector(true) {
                // Copy data from input list into vec_data
                std::copy(list.begin(), list.end(), std::back_inserter(vector_data));
            }
            /// Custom 2d input Matrix
            Matrix(std::initializer_list<std::initializer_list<dtype>> list) : row_dim(list.size()), isVector(false) {
                // Iterate through each row and add copy into data
                std::copy(list.begin(), list.end(), std::back_inserter(data));
            }

            /// Matrix reshaping

            /// Matrix boolean properties

            /// Matrix IO
            void print() {
                std::cout << "[";
                if (isVector) {
                    for (auto& el : vector_data) { 
                        std::cout << el << ", "; 
                    }
                }
                else {
                    for (int r = 0; r < row_dim; r++) {
                        for (auto& el : data[r]) {
                            std::cout << el << ", "; 
                        }
                        if (r != row_dim - 1) {
                            std::cout << std::endl;
                        }
                    }
                }
                std::cout << "]";
            }
    };
}
