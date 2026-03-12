#include <iostream>
#include <vector>

using namespace std;

struct IntPair {
    int x{};
    int y{};

    void print() {
        cout << "Pair(" << x << ", " << y << ")\n";
    }

    bool isEqual(const IntPair& other) {
        if (x == other.x && y == other.y) {
            return true;
        } else {
            return false;
        }
    }
};

class Point3d {
public:

    void setValues(int x, int y, int z) {
        m_x = x; m_y = y; m_z = z;
    }
    
    void print() const  {
        cout << "<" << m_x << " " << m_y << " " << m_z << ">\n";
    }

    bool isEqual(const Point3d& other) {
        return (m_x == other.m_x) && (m_y == other.m_y) && (m_z == other.m_z);
    }
    
private:
    int m_x{};
    int m_y{};
    int m_z{};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    IntPair p1{1 ,2};
    IntPair p2{3, 4};

    cout << "p1: ";
    p1.print();
    
    cout << "p2: ";
    p2.print();

    cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
    cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1 , 2, 3);

    std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;   
}