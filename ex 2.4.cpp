#include <iostream>
#include "myFunction.h"

#define summOfnum(x,y) ((x) + (y))

int MyNamespace::f(int a) {
    static int first = 0;
    std::cout << a + first << std::endl;
    first = a;
    return 0;
}

int main() {
    MyNamespace::f(5);
    std::cout << summOfnum(3, 5) << std::endl;
    return 0;
}s