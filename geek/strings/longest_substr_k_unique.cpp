#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
    Longest substring with k unique characters
    
    Given a string s and a non negative integer k, 
    find the length of the longest substring that 
    contains exactly k distinct characters.
    If no such substring exists, return -1.

*/

// Naive approach 
// O(n^2) time
// O(1) space
int longestKSubstr(const string& s, int k) {
    int ans = - 1;
    unordered_set<char> unique;
    for (int i = 0; i < s.size(); i++) {
        unique.clear();

        for (int j = i; j < s.size(); j++) {
            unique.insert(s[j]);
            if (unique.size() == k ){
                ans = max(ans, j - i + 1);
            }
            if (unique.size() > k) break;
        }
    }
    return ans;
}

// Prefix sums and Binary search 
// O(n log(n)) Time
// O(n) space
int longestKSubstr2(const string& s, int k) {
    int n = s.size();
    vector<vector<int>> frq(n, vector<int>(26));
    
    for (int i = 0; i < n; i++) {
        frq[i][s[i] - 'a']++;
        if (i > 0) {
            for (int j = 0; j < 26; j++) {
                frq[i][j] += frq[i-1][j];
            }
        }
    }

    int ans = -1;

    for (int i = 0; i < n; i++) {
        int low = i, high = n-1, curr_ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            vector<int> freq = frq[mid];

            if (i > 0) {
                for (int j = 0; j < 26; j++) {
                    freq[j] -= frq[i-1][j];
                }
            }

            for (int j = 0; j < 26; j++) {
                if (freq[j] > 0) count++;
            }

            if (count == k) {
                curr_ans = mid - i + 1;
                low = mid + 1;
            } else if (count < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (curr_ans != -1) {
            ans = max(ans, curr_ans);
        }
    }
    return ans;
}

// Sliding window with frequency count 
// O(n) Time
// O(1) space
int longestKSubstr3(const string& s, int k) {
    int n = s.size();
    int i = 0, j = 0;
    int cnt = 0, ans = 0;
    vector<int> frq(26);

    while (j < n) {
        frq[s[j] - 'a']++;

        if (frq[s[j] - 'a'] == 1) cnt++;
        
        while (cnt > k) {
            if (--frq[s[i] - 'a'] == 0) cnt--;
            i++;
        }

        if (cnt == k) {
            ans = max(ans, j - i + 1);
        }
        j++;
    }
    return ans;
}

/*
    Binary Search
    Given a string str and an integer K, the task is to print the 
    length of the longest possible substring that has exactly K unique 
    characters. If there is more than one substring of the longest possible 
    length, then print any one of them or print -1 if there is no such substring
     possible.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "aabacbebebe";
    int k = 3;

    cout << longestKSubstr3(s, k) << '\n'; 

    return 0;
}