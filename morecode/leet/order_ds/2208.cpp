#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Soltuion {
public:
    int halveArray(vector<int>& arr) {
        int n = arr.size();
        priority_queue<double> pq;
        double sum = 0;
        for (auto& x : arr) {
            sum += x;
            pq.push(x);
        }
        sum /= 2.0;
        int ans = 0;
        while (sum > 0) {
            ans++;
            double x = pq.top() / 2.0;
            pq.pop();
            sum -= x;
            pq.push(x);
        }
        return ans;
    }
};

int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    Soltuion sol;
    vector<int> a{5, 19, 8, 1};
    cout << sol.halveArray(a) << '\n';
    return 0;   
}