#include "matrix.hpp"
#include <iostream>


int main() {
    linalg::Matrix<int> m = {{1,2}, {3,4}};;
    m.print();
    return 0;
} 