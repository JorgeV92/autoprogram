#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

// # Question 1
class Point2d {
public:
    Point2d() = default;
    Point2d(double x, double y) : m_x{x}, m_y{y} {}

    double distanceTo(const Point2d& other) const {
        double l = (m_x - other.m_x)*(m_x - other.m_x);
        double r = (m_y - other.m_y) * (m_y - other.m_y);
        return sqrt(l + r);
    }

    void print() {
        cout << "Point2d(" << m_x << ", " << m_y << ")\n";  
    }
private:
    double m_x{0.0};
    double m_y{0.0};
};

// # Question 2

class Fraction {
public:
    explicit Fraction (int num = 0, int den = 1) : m_numerator{num}, m_denominator{den} {}

    void getFraction() {
        cout << "Enter a value for numerator: ";
        cin >> m_numerator;
        cout << "Enter a value for denominator: ";
        cin >> m_denominator;
        cout << endl;
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction{m_numerator * other.m_numerator, m_denominator * other.m_denominator};
    }

    void printFraction() const {
        cout << m_numerator << "/" << m_denominator << endl;
    }

private:
    int m_numerator{0};
    int m_denominator{1};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Point2d first{};
    // Point2d second(3.0, 4.0);
    // first.print();
    // second.print();

    // cout << "Distance between two points: " << first.distanceTo(second) << endl;

    Fraction f1{};
    f1.getFraction();

    Fraction f2{};
    f2.getFraction();

    cout << "Fraction multiplied: ";
    f1.multiply(f2).printFraction();
    
    return 0;   
}