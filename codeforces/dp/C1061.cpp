#include <iostream>
#include <vector>
#include <cstdint>
#include <stack>
using namespace std;

template<unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline ui pow(ui a, ui p) {ui r = 1, e = a;while (p) {if (p&1) {r = ((ull)r * e) % N;}e = ((ull)e*e) % N;p >>= 1;}return r;}
    inline ui inv(ui a) { return pow(a, N-2); }
public:
    inline Field(int x= 0) : v(x) {}
    inline Field<N>& operator+=(const Field<N>& o) {if (v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
    inline Field<N>& operator*=(const Field<N>& o) { v = (ull)v*o.v % N; return *this; }
    inline Field<N>& operator/=(const Field<N>& o) {return *this = inv(o.v); }
    inline Field<N>& operator-=(const Field<N>& o) {if (v < o.v) v -= o.v-N; else v -= o.v; return *this;}
    inline Field<N> operator*(const Field<N>& o) const {Field<N>r{*this}; return r *= o;}
    inline Field<N> operator/(const Field<N>& o) const {Field<N>r{*this}; return r /= o;}
    inline explicit operator ui() const { return v; }
    inline static vector<Field<N>> fact(int t) {
        vector<Field<N>> F(t+1, 1);
        for (int i = 2; i <= t; ++i) {
            F[i] = F[i-1] * i;
        }
        return F;
    }
    inline static vector<Field<N>> invfact(int t) {
        vector<Field<N>> F(t+1, 1);
        Field<N> X{1};
        for (int i = 2; i <= t; i++) {
            X = X*i;
        }
        F[t] =  1 / X;
        for (int i = t-1; i >= 2; --i) {
            F[i] = F[i+1] * (i+1);
        }
        return F;
    }
private:
    ui v;
};
template<unsigned int N> Field<N> operator*(int i, const Field<N>& f) {return Field<N>(i)*f;}
template<unsigned int N> Field<N> operator/(int i, const Field<N>& f) {return Field<N>(i)/f;}
template<unsigned int N>ostream& operator<<(std::ostream& os, const Field<N>& f) {return os<<(unsigned int)f; } 


typedef Field<int(1e9)+7> FF;

const int maxv = 1e6 + 5;
const int maxn = 1e5 + 5;
int N;
FF dp[maxv];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    dp[0] = 1;
    FF res = 0;
    stack<int> facs;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        for (int f = 1; f <= a / f; f++) {
            if (a % f == 0) {
                res += dp[f-1];
                if (f < a/f) {
                    res += dp[a/f-1];
                    dp[a/f] += dp[a/f-1];
                }
                facs.push(f);
            }
        }
        while (!facs.empty()) {
            int f = facs.top(); facs.pop();
            dp[f] += dp[f-1];
        }
    }
    cout << res << "\n";
    return 0;
}