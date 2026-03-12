#include <iostream>
#include <vector>

using namespace std;

struct Date {
    int day{};
    int month{};
    int year{};
};

void printDate(const Date& date) {
    std::cout << date.day << '/' << date.month << '/' << date.year;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Date date{ 4, 10, 21 };
    printDate(date);
    
    return 0;
}