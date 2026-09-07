#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;
    int dp[2001];
    vector<int> prev;

    int solve(int n) {
        if (n == 0) return 1;

        if (dp[n] != -1) return dp[n];

        int total = (2 * solve(n - 1)) % M;

        if (prev[n] != 0) {
            int duplicates = solve(prev[n] - 1);
            total = (total - duplicates + M) % M;
        }

        return dp[n] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));

        prev.assign(n + 1, 0);

        // last[c] = last position where character c appeared & Positions are 1-based
        vector<int> last(256, 0);

        for (int i = 1; i <= n; i++) {
            prev[i] = last[s[i - 1]];
            last[s[i - 1]] = i;
        }

        return (solve(n) - 1 + M) % M;
    }
};