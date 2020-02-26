#include "matrix.h"
#include <iostream>

int main () {

    size_t rows = 3, cols = 3;
    Matrix m(rows, cols);
    Matrix n(rows, cols);

    m.softreset();
    m.print();

    for (int i = 0; i < rows * cols; i++) {
        n.M[i] = -3;
    }

    for (int i = 0; i < rows * cols; i++) {
        m.M[i] = -2;
    }

    // try {
    //     Matrix o = m + n;
    //     o.print();   
    // }
    // catch(std::string err) {
    //     std::cout << err;
    // }

    m.print();
    n.print();
    
    Matrix x = (n * m);
    x.print();

    return 0;
}