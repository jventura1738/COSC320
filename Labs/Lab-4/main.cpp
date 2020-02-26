#include "matrix.h"
#include <iostream>

int main () {

    size_t rows = 3, cols = 3;
    Matrix m(rows, cols);

    m.softreset();
    m.print();

    return 0;
}