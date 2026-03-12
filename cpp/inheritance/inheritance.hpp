#include <string>
#include <string_view>
#include <iostream>

class Nexus {
public:
    std::string m_name{};
    int m_age;

    Nexus(std::string_view name = "", int age = 0)  
        : m_name{name}, m_age{age} {}
    
    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

class Player : public Nexus {
public:
    double m_winAverage{};
    int m_games{};

    Player(double winA = 0.0, int games = 0) 
        : m_winAverage{winA}, m_games(games) {}
};

class Drone : public Nexus {
public:    
    double m_batteryLife{};
    long m_nexusID{};

    Drone(double battery = 0.0, long id = 0) 
        : m_batteryLife{battery}, m_nexusID{id} {}

    void printNameAndBattery() const {
        std::cout << m_name << ": " << m_batteryLife << std::endl;
    }
};

