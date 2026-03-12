#include <iostream>
#include <vector>
#include <chrono>

using namespace std; 

class Timer {
public:
    void reset() {
        m_beg = Clock::now();
    }

    double elapsed() const {
        return chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }

private:
    using Clock = chrono::steady_clock;
    using Second = chrono::duration<double, ratio<1>>;
    chrono::time_point<Clock> m_beg{ Clock::now() };
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Timer tm;
    int t{};
    cin >> t;
    while (t--) {
        int n{};
        cin >> n;
        vector<int> arr(n);
        int pos{}, neg{};
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] > 0) {
                pos++;
            } else {
                neg++;
            }
        }

        int ops = 0;
        while (pos < neg || (neg&1)) {
            ops++;
            pos++;
            neg--;
        }

        cout << ops << endl;

        cout << tm.elapsed() << endl;
    }
    return 0;   
}