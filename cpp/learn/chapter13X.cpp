#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std; 

// # Question 1
struct Monster {
    enum Type {
        ogre,
        dragon,
        orc,
        giant_spider,
        slime,
    };
    Type mt{};
    string name{};
    double health{};
};

constexpr string_view getMonsterTypeString(Monster::Type type) {
    switch (type) {
        case Monster::ogre:             return "Ogre";
        case Monster::dragon:           return "Dragon";
        case Monster::orc:              return "Orc";
        case Monster::giant_spider:     return "Giant Spider";
        case Monster::slime:            return "Slime";
    }
    return "Unknown";
}

void printMonster(const Monster& monster) {
    cout << "This " << getMonsterTypeString(monster.mt) <<
        " is named " << monster.name << " and has " << 
        monster.health << " health.\n";
}

// Question 2
template<typename T>
class Triad {
public:
    T a{}, b{}, c{};
};

template <typename T>
void print(const Triad<T>& triad) {
    cout << "[" << triad.a << ", " << triad.b << ", " << triad.c << "]\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Monster ogre{ Monster::ogre, "Torg", 145 };
    Monster slime{ Monster::slime, "Blurp", 23 };
    printMonster(ogre);
    printMonster(slime);

    Triad<int> t1{1, 2, 3};
    print(t1);
    Triad<double> t2{1.2, 3.4, 5.6};
    print(t2);

    return 0;
}