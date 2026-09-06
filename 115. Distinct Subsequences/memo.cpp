#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> dp;

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        dp.assign(n, vector<long long>(m, -1));

        return solve(s, t, 0, 0);
    }

    long long solve(string &s, string &t, int i, int j) {

        // t completely matched
        if (j == t.size())
            return 1;

        // s finished before t
        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;

        // Characters match
        if (s[i] == t[j]) {
            // Take s[i]
            ans += solve(s, t, i + 1, j + 1);

            // Don't take s[i]
            ans += solve(s, t, i + 1, j);
        }
        else {
            // Can't take s[i]
            ans += solve(s, t, i + 1, j);
        }

        return dp[i][j] = ans;
    }
};