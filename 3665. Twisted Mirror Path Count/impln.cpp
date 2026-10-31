#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int dp[501][501][2];

    int solve(vector<vector<int>>& grid, int i, int j, int dir) {
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j][dir] != -1) return dp[i][j][dir];

        // Mirror encountered
        if(grid[i][j] == 1) {
            if(dir == 0) {
                return dp[i][j][dir] = solve(grid, i+1, j, 1);
            }
            else {
                return dp[i][j][dir] = solve(grid, i, j+1, 0);
            }
        }

        // Empty cell
        int right = solve(grid, i, j+1, 0);
        int down = solve(grid, i+1, j, 1);

        return dp[i][j][dir] = (right + down) % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0, 0);
    }
};