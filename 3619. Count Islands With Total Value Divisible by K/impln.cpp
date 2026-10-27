#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 

    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int sum = grid[i][j]; // add the value of the current cell
        grid[i][j] = 0; // mark the cell as visited

        sum += dfs(grid, i + 1, j, m, n);
        sum += dfs(grid, i - 1, j, m, n);
        sum += dfs(grid, i, j + 1, m, n);
        sum += dfs(grid, i, j - 1, m, n); //{{0,-1},{0,1},{-1,0},{1,0}}

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k){
        int m = grid.size(); // number of rows
        int n = grid[0].size(); // number of columns

        int count = 0;

        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) { // found an island
                    int sum = dfs(grid, i, j, m, n); // mark the island as visited
                        if (sum % k == 0) {
                            count++;
                        }
                }
            }
        }
        return count;
    }
};