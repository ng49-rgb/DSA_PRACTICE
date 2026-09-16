#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    long long dp[1005][1005];

    long long solve(int i, int k, int n) {
        if (k == 0) return 1;
        // Not enough points left
        if (i >= n) return 0;

        if (dp[i][k] != -1) return dp[i][k];

        long long ans = 0;

        // NOT TAKE
        ans += solve(i + 1, k, n);

        // TAKE: Choose j > i and make [i, j] a segment
        for (int j = i + 1; j < n; j++) {
            ans += solve(j, k - 1, n);
            ans %= mod;
        }

        return dp[i][k] = ans % mod;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));

        return solve(0, k, n);
    }
};