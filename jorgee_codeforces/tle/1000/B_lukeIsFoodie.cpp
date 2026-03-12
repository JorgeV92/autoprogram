#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mn = a[0], mx = a[0];
    for (int i = 0; i < n; i++) {
        mn = min(a[i], mn);
        mx = max(a[i], mx);
        if (mx - mn > 2 * x) {
            ans++;
            mn = mx = a[i];
        }
    }
    cout << ans << '\n';
}


/*
Debug-print version.

Key invariant:
- We are trying to extend a current segment (block) of piles where Luke can keep the
  SAME affinity v and still eat every pile in that segment.
- A pile with value a[i] allows v in [a[i]-x, a[i]+x].
- A common v exists for the whole segment iff (max a - min a) <= 2x.

We keep:
  mn = min a in current segment
  mx = max a in current segment

When mx - mn > 2x, the segment becomes impossible, so we must "change v" right
before pile i, count one change, and start a new segment at i.
*/

void solve2() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int changes = 0;

    long long mn = a[0], mx = a[0];

    cout << "\n[debug] n=" << n << " x=" << x << "\n";
    cout << "[debug] a: ";
    for (auto v : a) cout << v << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) {
        long long old_mn = mn, old_mx = mx;

        // Try to include a[i] in the current segment
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);

        cout << "\n[debug] i=" << i
             << "  a[i]=" << a[i] << "\n";
        cout << "  before: mn=" << old_mn << " mx=" << old_mx
             << "  (spread=" << (old_mx - old_mn) << ")\n";
        cout << "  after : mn=" << mn << " mx=" << mx
             << "  (spread=" << (mx - mn) << ")\n";
        cout << "  need spread <= 2x = " << (2LL * x) << "\n";

        if (mx - mn > 2LL * x) {
            cout << "  -> spread too big! mx-mn=" << (mx - mn)
                 << " > " << (2LL * x) << "\n";
            cout << "  -> must CHANGE v before eating pile i=" << i << "\n";

            changes++;

            // Start new segment at i
            mn = mx = a[i];

            cout << "  -> changes now = " << changes << "\n";
            cout << "  -> start new segment at i=" << i
                 << " with mn=mx=" << a[i] << "\n";
        } else {
            cout << "  -> ok: can keep same v for current segment\n";
        }
    }

    cout << "\n[debug] final changes = " << changes << "\n";
    cout << changes << "\n";
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve2();
    }
    return 0;
}


