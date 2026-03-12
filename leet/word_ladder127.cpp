#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words_set(wordList.begin(), wordList.end());
    if (words_set.find(endWord) == words_set.end()) return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while (!q.empty()) {
        auto [word, cnt] = q.front(); 
        q.pop();
        if (word == endWord) {
            return cnt;
        }
        for (int i = 0; i < word.size() ; i++) {
            char tmp = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == tmp) continue;
                word[i] = c;
                if (words_set.find(word) != words_set.end()) {
                    q.push({word, cnt+1});
                    words_set.erase(word);
                }
            }
            word[i] = tmp;
        }
    }
    return 0;
}

int main() {
    return 0;
}