#include <iostream>
#include "../../lib/matrix/matrix.hpp"

/// Tranpose Matrix Tests
bool square_test() {
    std::cout << "<-Square Matrix Transpose Test->" << std::endl;
    linalg::Matrix<int> m1 = {{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10}, 
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25},
                    };
    linalg::Matrix<int> m2 = {{1, 6, 11, 16, 21},
                        {2, 7, 12, 17, 22}, 
                        {3, 8, 13, 18, 23},
                        {4, 9, 14, 19, 24},
                        {5, 10, 15, 20, 25},
                    };
    // Transpose m1, should be equal to m2
    if (m1.transpose() == m2) {
        std::cout << "Success!" << std::endl;
        return true;
    }
    else {
        std::cout << "TEST FAILED" << std::endl;
    }
    return false;
}

bool tall_wide_test() {
    std::cout << "<-Tall/Wide Matrix Transpose Test->" << std::endl;
    linalg::Matrix<int> m1 = {{1, 2, 3},
                            {6, 7, 8}, 
                            {11, 12, 13},
                            {16, 17, 18},
                            {21, 22, 23},
                    };
    linalg::Matrix<int> m2 = {{1, 6, 11, 16, 21},
                            {2, 7, 12, 17, 22}, 
                            {3, 8, 13, 18, 23},
                    };
    // Transpose m1, should be equal to m2
    // Transpose + Transpose m1 should be equal to m1
    if (m1.transpose() == m2 && m1.transpose().transpose() == m1) {
        std::cout << "Success!" << std::endl;
        return true;
    }
    else {
        std::cout << "TEST FAILED" << std::endl;
    }
    return false;
}


int main() {
    std::cout << "<<<Matrix Transpose Test Suit>>>" << std::endl;
    square_test();
    tall_wide_test();
    return 0;
}