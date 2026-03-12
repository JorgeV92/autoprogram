#include <iostream>
#include <vector>
#include <string>

using namespace std; 

/*
    Longest Common Prefix using Sorting

    Given an array of strings arr[], the task is to return the 
    longest common prefix among each and every strings present 
    in the array. If there’s no prefix common in all the strings, 
    return “”.
*/

// O(n log n )
// O(m)
void LCP(vector<string>& strs) {
    if (strs.empty()) {
        cout << "" << endl;
        return;
    }
    sort(strs.begin() , strs.end());
    string F = strs.front();
    string L = strs.back();
    int mn = min(F.size(), L.size());
    int i = 0;
    while (i < mn && F[i] == L[i]) i++;
    cout <<  F.substr(0,i ) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> arr = {"geeksforgeeks", "geeks",
                           "geek", "geezer"};
    LCP(arr);
    return 0;   
}