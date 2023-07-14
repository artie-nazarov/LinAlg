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
        using type1d = std::vector<dtype>;
        using type2d = std::vector<std::vector<dtype>>;
        private:
            /// Class properties
            /// int row and column dimensions of the Matrix object
            int row_dim;
            int col_dim;
            /// std::vector object containing a 2D Matrix
            /// we use a 1d vector type to store all data
            /// All matrix operations will assume dimensions defined in row_dim and col_dim
            type1d data;

            /// Bolean properties
            /// is the Martix object a 1D vector
            bool isVector;

        public:
            /// Constructors
            /// Default constructor
            Matrix() : row_dim(1), col_dim(1), isVector(true), type1d(1, 0) {}
            /// Single dim Matrix (vector)
            Matrix(int dim) : isVector(true), row_dim(1), col_dim(dim), type1d(dim, 0) {}
            /// 2-dim Matrix
            Matrix(int rows, int cols) : row_dim(rows), col_dim(cols), isVector(false) {
                // Initialze data with 2D std::vector of size rows x cols filled with 0's
                data = type1d(row_dim * col_dim, 0);
            }
            /// Custom 1d input Matrix (vector)
            Matrix(std::initializer_list<dtype> list) : row_dim(1), col_dim(list.size()), isVector(true) {
                // Copy data from input list into vec_data
                std::copy(list.begin(), list.end(), std::back_inserter(data));
            }
            /// Custom 2d input Matrix
            Matrix(std::initializer_list<std::initializer_list<dtype>> list) : row_dim(list.size()), isVector(false) {
                // Iterate through each row and add copy into data
                int i = 0;
                col_dim = list.begin()[0].size();
                data = std::vector<dtype>(col_dim*row_dim);
                for (auto row : list) {
                    // check column dimension
                    if (col_dim != row.size()) {
                        throw std::invalid_argument("Inconsistent column dimension"); 
                    }
                    std::copy(row.begin(), row.end(), data.begin()+col_dim*i++);
                }
            }
            /// Custom 1d input Matrix (vector)
            Matrix(std::vector<dtype> list) : row_dim(1), col_dim(list.size()), isVector(true) {
                // Copy data from input list into vec_data
                std::copy(list.begin(), list.end(), std::back_inserter(data));
            }
            /// Custom 2D std::vector input
            Matrix(std::vector<std::vector<dtype>> list) : row_dim(list.size()), isVector(false) {
                // Iterate through each row and add copy into data
                int i = 0;
                col_dim = list[0].size();
                for (auto row : list) {
                    // check column dimension
                    if (col_dim != row.size()) {
                        throw std::invalid_argument("Inconsistent column dimension"); 
                    }
                    std::copy(row.begin(), row.end(), data.begin()+col_dim*i++);
                }
            }
    

            /** Matrix reshaping
             * Notes:
             *  1. Matrix reshaping doesn't automatically perform memory reshaping.
             *  2. Memory layout may be done lazily in the future if necessary
             *  3. Reshape functions are used to fill up dimensions for allocated memory
             *     This means that new dim1 & dim2 must fit into the original (row_dim * col_dim) size
            */
            /// Reshape a Matrix to a 1d column vector
            void reshape(int dim1) {
                row_dim = 1;
                col_dim = dim1;
                isVector = true;
            }
            /// Reshape a Matrix to another 2d matrix.
            /// Dimensions MUST fit preallocated (row_dim * col_dim) number of elements
            void reshape(int dim1, int dim2) {/*TODO*/}

            /// Matrix Transpose
            Matrix transpose() {
                // Call into a desired transpose implementation
                std::vector<dtype> transposed_mat(data.size());
                transpose_simple(transposed_mat);
                Matrix mat(transposed_mat);
                mat.col_dim = row_dim;
                mat.row_dim = col_dim;
                return mat;
            }
            // Simple Transpose
            // @param mat an empty vector to be filled in with transpose
            void transpose_simple(std::vector<dtype>& mat) {
                for (int i = 0; i < row_dim*col_dim; i++) {
                    int ridx = i / row_dim;
                    int cidx = i % row_dim;
                    mat[i] = data[cidx*col_dim + ridx];
                }
            }

            /// Operator overloading
            /// Equality
            bool operator==(const Matrix &m) {
                // Check dimensions
                if (row_dim != m.row_dim || col_dim != m.col_dim) {
                    return false;
                }
                // Check each data element
                if (data != m.data) {
                    return false;
                }
                return true;
            }

            /// Matrix IO
            void print() {
                std::cout << "Shape (" << row_dim << ", " << col_dim << ")\n";
                for (int i = 0; i < row_dim; i++) {
                    for (int j = 0; j < col_dim; j++) {
                        std::cout << data[i*col_dim + j] << " ";
                    }
                    std::cout << std::endl;
                }
            }
    };

    /// Various Matrix objects
    /// Zeros Matrix
    template <typename dtype>
    Matrix<dtype> zeros() {
        return Matrix<dtype>();
    }
    template <typename dtype>
    Matrix<dtype> zeros(int dim1) {
        return Matrix<dtype>(dim1);
    }
    template <typename dtype>
    Matrix<dtype> zeros(int dim1, int dim2) {
        return Matrix<dtype>(dim1, dim2);
    }

    /// Ones Matrix
    
    /// Eye Matrix
}
