#include "fibonacci.h"
#include <iostream>

void fibonacciLoop(int a, int b, int max) {
    int c = a + b;
    std::cout << c << " ";
    if (a + b < max) {
        fibonacciLoop(b, c, max);
    }
}

void fibonacci1() {
    std::cout << "0 1 ";
    fibonacciLoop(0, 1, 500);
    std::cout << std::endl;
}

void fibonacci2() {
    int a = 0;
    int b = 1;
    int swap = 0;

    std::cout << a << " " << b << " ";

    for (int i = 0; i < 14; i++) {
        swap = b;
        b += a;
        a = swap;
        std::cout << b << " ";
    }

    std::cout << std::endl;
}