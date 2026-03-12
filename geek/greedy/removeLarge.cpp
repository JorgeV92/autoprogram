#include <iostream>
#include <vector>

using namespace std;
 
int cost(vector<int>& arr) {
    int n = arr.size();
    int mn = *min_element(arr.begin(), arr.end());
    return mn * (n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = { 4, 3, 2 };
    cout << cost(a) << endl;
    
    return 0;
}