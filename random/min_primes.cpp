#include <iostream>
#include <vector>

using namespace std; 


vector<bool> getFirstMPrimes(int n) {;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i*i <= n) {
            for (int j = i*i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

int min_primes_sum(int N, int M) {

    auto is_primes = getFirstMPrimes(N);
    vector<int> primes;
    for (int x = 2; x <= N; x++) {
        if (primes.size() == M) break;
        if (is_primes[x]) 
            primes.push_back(x);
    }

    vector<int> dp(N+1, 1e9);
    dp[0] = 0;
    for (int p : primes) {
        for (int x = p; x <= N; x++) {
            dp[x] = min(dp[x], dp[x-p] + 1);
        }
    }

    return (dp[N] >= 1e9) ? -1 :  dp[N];
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << min_primes_sum(11,3) << '\n';

    return 0;
}