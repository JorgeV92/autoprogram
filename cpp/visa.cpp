#include <iostream>
#include <string>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define vi vector<int>
#define ll long long

template <typename T>
void printArr(const vector<T>& A) {
    for (const T& x : A) cout << x << " ";
    cout << endl;
} 

vector<long long> solutionIntevalSeg(vector<vector<long long>>& segments) {
    vector<ll> res;
    vector<pair<ll, ll>> merged;
    for (auto& seg : segments) {
        ll l = seg[0], r = seg[1];
        merged.push_back({l, r});
        sort(all(merged));
        vector<pair<ll,ll>> temp;
        ll curL = merged[0].first, curR = merged[0].second;
        for (int i = 1; i < merged.size(); i++) {
            if (merged[i].first <= curR + 1) {
                curR = max(curR, merged[i].second);
            } else {
                temp.push_back({curL, curR});
                curL = merged[i].first;
                curR = merged[i].second;
            }
        }
        temp.push_back({curL, curR});
        merged = temp;

        ll total = 0;
        for (auto& p : merged) {
            total += (p.second - p.first + 1);
        }
        res.push_back(total);
    }
    return res;
}

void solutinTeeMatrix(vector<vector<int>>& matrix) {
    int count = 0;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            set<int> elements; 
            for (int k = 0; k < m; k++) {
                if (k != i) {
                    elements.insert(matrix[k][j]);
                }
            }

            for (int k = 0; k < n; k++) {
                if (k != j) {
                    elements.insert(matrix[i][k]);
                }
            }

            if (elements.size() == 1) count++;
        }
    }

    cout << count << endl;
}

vector<int> highlishtSolution(vector<int> heights) {
    vector<int> highlightOrder;

    while (true) {
        vector<int> highlights;

        // Identify highlights
        for (int i = 0; i < (int)heights.size(); ++i) {
            if ((i == 0 || heights[i] > heights[i - 1]) &&
                (i == heights.size() - 1 || heights[i] > heights[i + 1])) {
                highlights.push_back(heights[i]);
            }
        }

        if (highlights.empty()) break; // no highlights left

        // Find the smallest highlight
        int smallest = *min_element(highlights.begin(), highlights.end());

        // Remove it from heights
        heights.erase(find(heights.begin(), heights.end(), smallest));

        // Append to answer
        highlightOrder.push_back(smallest);
    }

    return highlightOrder;
}


int main() {
    // vi a{5, 3, 2, 6, 7, 9, 10};
    // printArr(a);
    // a.erase(find(all(a), 6));
    // printArr(a);

    // vector<vector<ll>> segments{
    //     {1,9}, {1,3}, {8,15}, {6,9}, {2,5}
    // };
    // printArr(solutionIntevalSeg(segments));

    vector<vi> m{
        {1, 1, 1, 1 },
        {2,3,1,1},
        {1,1,1,0},
        {1,4,1,1}
    };
    solutinTeeMatrix(m);
    return 0;
}

/*
        Given a pair of locations of sprinklers in in (x, y)

        and a source of water (0, 0) calcualte the shortest path to each sprinkler 
        that we can connect all sprinklers for example [(1,2), (3, 4), (2, 5)]

            [W.........X.........]
            [..............X....]
            [..X.................]
            [..........X.........]
*/