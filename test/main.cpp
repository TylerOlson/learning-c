#include "fibonacci.h"
#include <iostream>

void add(int &foo) {
    foo++;
}

int main() {
    int foo = 1;
    add(foo);

    fibonacci1();
    fibonacci2();
    return 0;
}
