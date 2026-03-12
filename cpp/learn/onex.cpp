#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /// # Question 3
    cout << "Input first number: ";
    int x{};
    int y{};
    cin >> x;
    cout << "Input second number: ";
    cin >> y;
    cout << "Sum of elements: " << (x+y) << " " << "Subtraction of elements: " << (x-y) << endl;
    return 0;
}