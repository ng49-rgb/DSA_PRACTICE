#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int ans = INT_MAX;

    void solve(vector<vector<int>>& grid, int i, int j, int xr) {
        if (i >= m || j >= n) {
            return;
        }

        xr ^= grid[i][j];

        if (i == m - 1 && j == n - 1) {
            ans = min(ans, xr);
            return;
        }

        solve(grid, i, j + 1, xr);
        solve(grid, i + 1, j, xr);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        ans = INT_MAX;

        solve(grid, 0, 0, 0);

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18}, {19, 20, 21}, {22, 23, 24}, {25, 26, 27}, {28, 29, 30} };
    int result = solution.minCost(grid);
    cout << "Minimum XOR cost: " << result << endl;
    return 0;
}