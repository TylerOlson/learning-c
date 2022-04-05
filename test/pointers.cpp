#include <iostream>

void add(int *foo) {
    *foo += 1;
}

int pointers() {
    int foo = 1;
    int *fooptr = &foo;

    add(fooptr);
    add(&foo);

    std::cout << "Value of foo:                    " << foo << std::endl;
    std::cout << "Address of foo:                  " << &foo << std::endl;
    std::cout << "Value of fooptr (foo's address): " << fooptr << std::endl;
    std::cout << "Address of fooptr                " << &fooptr << std::endl;
    std::cout << "Value of address in foopt:       " << *fooptr << std::endl;
    return 0;
}
