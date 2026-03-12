#include <iostream>
#include <vector>
#include <string>

using namespace std; 

/*
    Longest substring where all the characters appear at least K times | Set 3

    Given a string str and an integer K, the task is to find the length of the 
    longest substring S such that every character in S appears at least K tim
*/

int longestSubstring(string& s, int k) {
    int ans = 0;
    vector<int> frq(26);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        frq[s[i]-'a']++;
    }

    int unique = 0;
    for (int x : frq) {
        if (x != 0) unique++;
    }

    for (int i = 0; i <= unique; i++) {
        frq.assign(26, 0);
        int l = 0, r = 0;
        int cnt = 0, cntk = 0;

        while (r < n) {
            if (cnt <= i) {
                int idx = s[r] - 'a';
                if (frq[idx] == 0) cnt++;
                frq[idx]++;
                if (frq[idx] == k) cntk++;
                r++;
            } else {
                int idx = s[l] - 'a';
                if (frq[idx] == k) cntk--;
                frq[idx]--;
                if (frq[idx] == 0) cnt--;
                l++;
            }

            if (cnt == i && cntk == i) {
                ans = max(ans, r - l);
            }
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S = "aabbba";
    int K = 3;
    cout << longestSubstring(S, K) << endl;

    return 0;
}

