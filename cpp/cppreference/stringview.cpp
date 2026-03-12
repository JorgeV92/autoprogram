#include <iostream>
#include <string_view>

#define A "▀"
#define B "▄"
#define C "─"

int main() {
    constexpr std::string_view blocks[]{A B C, B A C, A C B, B C A};

    for (int y{}, p{}; y != 8; y++, p = ((p+1) % 4)) {
        for (char x{}; x != 29; x++) {
            std::cout << blocks[p];
        }
        std::cout << '\n';
    }
    
    return 0;
}