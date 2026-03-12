#include <iostream>
#include "io.h"

int readNumber() {
    std::cout << "Input numebr: ";
    int x{};
    std::cin >> x;
    return x;
}

void writeAnswer(int x) {
    std::cout << "Sum is: " << x << std::endl;
}

