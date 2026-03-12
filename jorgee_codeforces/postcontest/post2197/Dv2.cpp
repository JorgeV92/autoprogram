#include <iostream>
#include <vector>
#include <cstdint>
#include <iomanip>   // setw
#include <string>

using std::cout;
using std::cin;
using std::vector;
using int64 = long long;

// Toggle this to 1 to see debug output, 0 to silence.
static constexpr bool DEBUG = true;

// Optional: limit prints to avoid massive logs on big inputs.
static constexpr int MAX_I_TO_PRINT = 20;   // only print for i < 20
static constexpr int MAX_S_TO_PRINT = 50;   // only print for s <= 50

static void print_array(const vector<int>& a) {
    cout << "a = [";
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << (i + 1 == (int)a.size() ? "" : ", ");
    }
    cout << "]\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (DEBUG) {
            cout << "\n====================\n";
            cout << "Test case #" << tc << "\n";
            cout << "n = " << n << "\n";
            print_array(a);
            cout << "We count pairs (i, j) where a[i]*a[j] == (j - i)\n";
            cout << "Indexing here is 0-based.\n";
            cout << "--------------------\n";
        }

        int64 ans = 0;

        // Pass 1: treat i as LEFT endpoint.
        // We try s = a[j] but only when s <= a[i] to avoid double counting.
        if (DEBUG) cout << "\n[PASS 1] Fix i as LEFT endpoint; j = i + a[i]*s, check a[j]==s\n";

        for (int i = 0; i < n; i++) {
            int x = a[i];

            bool print_i = DEBUG && (i < MAX_I_TO_PRINT);
            if (print_i) {
                cout << "\n  i=" << i << " (a[i]=" << x << ")\n";
            }

            for (int s = 1; s <= x && i + (int64)x * s < n; s++) {
                int j = (int)(i + (int64)x * s);
                bool print_s = print_i && (s <= MAX_S_TO_PRINT);

                if (print_s) {
                    cout << "    try s=" << std::setw(3) << s
                         << " -> j = i + a[i]*s = " << i << " + " << x << "*" << s
                         << " = " << j
                         << ", a[j]=" << a[j];
                }

                if (a[j] == s) {
                    ans++;
                    if (print_s) {
                        cout << "   MATCH!  (a[i]*a[j]=" << x << "*" << a[j]
                             << "=" << (int64)x * a[j]
                             << ", j-i=" << (j - i) << ")"
                             << "  ans=" << ans;
                    } else if (DEBUG) {
                        // even if we don't print every s, still show matches (bounded by i limit)
                        if (i < MAX_I_TO_PRINT) {
                            cout << "     MATCH: (i=" << i << ", j=" << j
                                 << ") with a[i]=" << x << ", a[j]=" << a[j]
                                 << "  ans=" << ans << "\n";
                        }
                    }
                }

                if (print_s) cout << "\n";
            }
        }

        // Pass 2: treat i as RIGHT endpoint.
        // We try s = a[left] but only when s < a[i] to avoid double counting when equal.
        if (DEBUG) cout << "\n[PASS 2] Fix i as RIGHT endpoint; left = i - a[i]*s, check a[left]==s\n";

        for (int i = 0; i < n; i++) {
            int y = a[i];

            bool print_i = DEBUG && (i < MAX_I_TO_PRINT);
            if (print_i) {
                cout << "\n  i=" << i << " (RIGHT endpoint, a[i]=" << y << ")\n";
            }

            for (int s = 1; s < y && i - (int64)y * s >= 0; s++) {
                int left = (int)(i - (int64)y * s);
                bool print_s = print_i && (s <= MAX_S_TO_PRINT);

                if (print_s) {
                    cout << "    try s=" << std::setw(3) << s
                         << " -> left = i - a[i]*s = " << i << " - " << y << "*" << s
                         << " = " << left
                         << ", a[left]=" << a[left];
                }

                if (a[left] == s) {
                    ans++;
                    if (print_s) {
                        // Verify the condition using (left, i) as (i, j) in math:
                        int64 prod = (int64)a[left] * a[i];
                        int64 dist = i - left;
                        cout << "  MATCH!  (a[left]*a[i]=" << a[left] << "*" << a[i]
                             << "=" << prod
                             << ", i-left=" << dist << ")"
                             << "  ans=" << ans;
                    } else if (DEBUG) {
                        if (i < MAX_I_TO_PRINT) {
                            cout << "    MATCH: (left=" << left << ", right=" << i
                                 << ") with a[left]=" << a[left] << ", a[right]=" << a[i]
                                 << "  ans=" << ans << "\n";
                        }
                    }
                }

                if (print_s) cout << "\n";
            }
        }

        if (DEBUG) {
            cout << "\nResult for test case #" << tc << ": ans = " << ans << "\n";
            cout << "====================\n";
        }

        // Required output (the judge expects only this line per test).
        // If DEBUG is true, you'll have extra output and it will NOT be accepted on CF.
        // So turn DEBUG=false before submitting.
        if (!DEBUG) {
            cout << ans << '\n';
        } else {
            // When debugging, still print the final answer clearly:
            cout << "ANSWER (what you'd submit): " << ans << "\n";
        }
    }

    return 0;
}