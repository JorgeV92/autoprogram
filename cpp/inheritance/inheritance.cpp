#include "inheritance.hpp"
#include <iostream>

int main() {
    Player pl{};
    pl.m_name = "X";
    std::cout << pl.getName() << std::endl;

    Drone drone{100.0, 1774};
    drone.m_name = "JX";
    drone.printNameAndBattery();
    
    return 0;
}