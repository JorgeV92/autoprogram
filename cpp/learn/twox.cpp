#include <iostream>
#include "io.h"

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // # Qeustion 1
    int x{readNumber()};
    int y{readNumber()};
    writeAnswer(x+y);

    return 0;
}