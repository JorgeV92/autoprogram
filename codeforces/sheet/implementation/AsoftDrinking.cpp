#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drink = k*l;
    int toasts = drink/nl;
    int limes = c*d;
    int salt = p/np;
    cout << min(toasts, min(limes, salt)) / n << '\n';

    return 0;
}