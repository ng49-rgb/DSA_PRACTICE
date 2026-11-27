#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int budget, int minPrice,vector<vector<int>>& items,vector<int>& copies, vector<vector<int>>& dp) {
        if (n == 0) {
            return budget / minPrice;
        }

        if (dp[n][budget] != -1) {
            return dp[n][budget];
        }

        // Not Take
        int notTake = solve(n - 1, budget, minPrice, items, copies, dp);

        // Take
        int take = 0;
        int price = items[n - 1][1];

        if (price <= budget) {
            take = 1 + copies[n - 1] + solve(n - 1, budget - price, minPrice, items, copies, dp);
        }

        return dp[n][budget] = max(take, notTake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> copies(n, 0);
        int minPrice = INT_MAX;

        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    copies[i]++;
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, -1));

        return solve(n, budget, minPrice, items, copies, dp);
    }
};
// [[2,4],[3,2],[4,1],[6,4],[12,4]], budget = 8
int main() {
    Solution solution;
    vector<vector<int>> items = {{2, 4}, {3, 2}, {4, 1}, {6, 4}, {12, 4}};
    int budget = 8;
    int result = solution.maximumSaleItems(items, budget);
    cout << "Maximum sale items: " << result << endl;
    return 0;
}