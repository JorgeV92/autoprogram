#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cassert>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

// Generic Sparse Table for idempotent range queries (min, max, etc.)
// T = type stored
// F = function used to combine two values
template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;                      // size of the input array
  vector<vector<T>> mat;      // mat[j][i] stores answer for range [i, i + 2^j - 1]
  F func;                     // merge function (min, max, or custom)

  // Build sparse table from array a using merge function f
  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());

    // Number of levels needed
    // Example: if n = 8, max_log = 4 (for lengths 1,2,4,8)
    int max_log = 32 - __builtin_clz(n);

    mat.resize(max_log);
    mat[0] = a; // level 0 = original array, segments of length 1

    // Build larger powers of 2
    for (int j = 1; j < max_log; j++) {
      // At level j, interval length is 2^j
      mat[j].resize(n - (1 << j) + 1);

      for (int i = 0; i <= n - (1 << j); i++) {
        // Merge two halves of length 2^(j-1)
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  // Query on range [from, to], inclusive
  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);

    // Largest power of 2 that fits in the interval length
    int lg = 32 - __builtin_clz(to - from + 1) - 1;

    // Use two overlapping intervals of length 2^lg
    // This works because min/max are idempotent operations
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;

  while (tt--) {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // Prefix sums:
    // pref[k] = a[0] + a[1] + ... + a[k-1]
    // so sum of subarray [l..r] = pref[r+1] - pref[l]
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }

    // b = [0, 1, 2, ..., n-1]
    // We will build a sparse table over indices,
    // where combining i and j returns the index with larger a[index].
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);

    // sa.get(l, r) returns the INDEX of the maximum element in a[l..r]
    SparseTable<int> sa(b, [&](int i, int j) {
      return a[i] > a[j] ? i : j;
    });

    // Sparse table for minimum prefix sum in a range
    SparseTable<long long> smin(pref, [&](long long i, long long j) {
      return min(i, j);
    });

    // Sparse table for maximum prefix sum in a range
    SparseTable<long long> smax(pref, [&](long long i, long long j) {
      return max(i, j);
    });

    bool ok = true;

    // Recursive divide-and-conquer:
    // For segment [l..r], let x = index of maximum element in this segment.
    // Then we check whether there exists any subarray [i..j] with i <= x <= j
    // such that sum(i..j) > a[x].
    //
    // If yes, then condition fails.
    //
    // Why only subarrays containing x?
    // Because subarrays entirely on the left/right are handled recursively.
    function<void(int, int)> Dfs = [&](int l, int r) {
      if (l > r) {
        return; // empty segment
      }

      // x = index of maximum element in current segment [l..r]
      int x = sa.get(l, r);

      // We want the maximum subarray sum among all subarrays [i..j]
      // such that l <= i <= x <= j <= r.
      //
      // sum(i..j) = pref[j+1] - pref[i]
      //
      // To maximize this:
      // - choose smallest pref[i] for i in [l..x]
      // - choose largest pref[j+1] for j+1 in [x+1..r+1]

      // Minimum prefix sum on the left side (possible starts)
      long long mn = smin.get(l, x);

      // Maximum prefix sum on the right side (possible ends + 1)
      long long mx = smax.get(x + 1, r + 1);

      // So (mx - mn) is the maximum possible sum of a subarray
      // inside [l..r] that contains x.
      //
      // Since a[x] is the maximum value in [l..r], any subarray containing x
      // has maximum = a[x].
      //
      // Therefore, if max possible sum > a[x], then there exists a bad subarray.
      if (a[x] < mx - mn) {
        ok = false;
      }

      // Recurse on left and right parts
      Dfs(l, x - 1);
      Dfs(x + 1, r);
    };

    // Start from whole array
    Dfs(0, n - 1);

    cout << (ok ? "YES" : "NO") << '\n';
  }

  return 0;
}