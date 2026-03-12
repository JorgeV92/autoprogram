#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*
    Given string str consists of only lowercase alphabets and an 
    integer K, the task is to count the number of substrings of 
    size K such that any permutation of the substring is a palindrome.
*/

int palindromicPermutations(string& s, int k) {
    vector<string> res;
    // O(n^3)
    // auto find_substrs = [&](string t) {
    //     for (int i = 0; i < t.size(); i++) {
    //         for (int j = i;j < t.size(); j++) {
    //             if (j-i+1 == k)
    //                 res.push_back(t.substr(i, j-i+1));
    //         }
    //     }
    // };
    // find_substrs(s);

    for (int i = 0; i <= s.size()- k; i++) {
        res.push_back(s.substr(i, k));
    }

    int count = 0;
    for (string str : res) {
        map<char, int> mp;
        for (char c : str) {
            mp[c]++;
        }
        int odd = 0;
        for (const auto& [k, v] : mp) {
            if (v & 1) {
                odd++;
            }
        }
        if (odd <= 1) count++;
    }
    return count;;
}

// O(n)
int countPalindromicPermutations(string& s, int k) {
    int n = s.size();
    vector<int> frq(26);
    for (int i = 0; i < k; i++) {
        frq[s[i]-'a']++;
    }
    int ans = 0;

    auto check = [&]() {
        int odd = 0;
        for (int x : frq) {
            if (x & 1) odd++;
        }
        return odd <= 1;
    };

    if (check()) {
        ans++;
    }

    int i = 0, j = k;

    while (j < n) {
        frq[s[i++] - 'a']--;
        frq[s[j++] - 'a']--;
        if (check()) ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abbabca";
    int k = 3;
    cout << countPalindromicPermutations(s, k) << endl;

    return 0;
}