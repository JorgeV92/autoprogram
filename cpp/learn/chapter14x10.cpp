#include <iostream>
#include <vector>
#include <string>
#include <string_view>

class Ball {
public:
    Ball() = default;
    
    Ball(std::string_view s, double r = 10.0) 
        : m_color {s}, m_radius{r} {} 

    const std::string& getColor() const {
        return m_color;
    }

    double getRadius() const {
        return m_radius;
    }

private:
    std::string m_color{"black"};
    double m_radius{10.0};
};

void print(const Ball& b) {
    std::cout << "Ball(" << b.getColor() << ", " << b.getRadius() << ")\n";
}


int main() {
    std::ios::sync_with_stdio(false);`
    std::cin.tie(nullptr);

    Ball blue {"blue", 10.0};
    print(blue);

    Ball red {"red", 12.0};
    print(red);

    return 0;
}