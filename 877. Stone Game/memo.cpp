#include <bits/stdc++.h>
using namespace std;

class Solution {
    int t[501][501];
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(t, -1, sizeof(t));
        int scoreDifference = helper(piles, 0, n - 1);
        
        return scoreDifference > 0; 
    }

    int helper(vector<int>& piles, int i, int j) {
        if (i > j) return 0;
        if (i == j) return piles[i];
        if (t[i][j] != -1) return t[i][j];

        int pickLeft = piles[i] - helper(piles, i + 1, j);
        int pickRight = piles[j] - helper(piles, i, j - 1);

        return t[i][j] = max(pickLeft, pickRight);
    }
};

int main() {
    Solution solution;
    vector<int> piles = {3, 9, 1, 2};
    bool result = solution.stoneGame(piles);
    cout << (result ? "Alice wins" : "Bob wins") << endl; 
    return 0;
}
