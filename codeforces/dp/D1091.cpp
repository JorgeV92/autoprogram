#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

template<unsigned int N> class XField {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline ui pow(ui a, ui p) {
        ui r = 1, e = a;
        while (p) {
            if (p&1) {
                r = ((ull)r * e) % N;
            }
            e = ((ull)e*e) % N;
            p >>= 1;
        }
        return r;
    }
    inline ui inv(ui a) { return pow(a, N-2); }
public:
    inline XField(int x= 0) : v(x) {}
    inline XField<N>& operator*=(const XField<N>& o) { v = (ull)v*o.v % N; return *this; }
    inline XField<N>& operator/=(const XField<N>& o) {return *this = inv(o.v); }
    inline XField<N>& operator-=(const XField<N>& o) {if (v < o.v) v -= o.v-N; else v -= o.v; return *this;}
    inline XField<N> operator*(const XField<N>& o) const {XField<N>r{*this}; return r *= o;}
    inline XField<N> operator/(const XField<N>& o) const {XField<N>r{*this}; return r /= o;}
    inline explicit operator ui() const { return v; }
    inline static vector<XField<N>> fact(int t) {
        vector<XField<N>> F(t+1, 1);
        for (int i = 2; i <= t; ++i) {
            F[i] = F[i-1] * i;
        }
        return F;
    }
    inline static vector<XField<N>> invfact(int t) {
        vector<XField<N>> F(t+1, 1);
        XField<N> X{1};
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
template<unsigned int N> XField<N> operator*(int i, const XField<N>& f) {return XField<N>(i)*f;}
template<unsigned int N> XField<N> operator/(int i, const XField<N>& f) {return XField<N>(i)/f;}
template<unsigned int N>ostream& operator<<(std::ostream& os, const XField<N>& f) {return os<<(unsigned int)f; } 

typedef XField<998244353> FF;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    auto F = FF::fact(n);
    auto I = FF::invfact(n);
    FF ans = n * F[n];
    for (int i = 1; i < n; i++) {
        ans -= F[n] * I[i];
    }
    cout << ans << '\n';
    return 0;   
}