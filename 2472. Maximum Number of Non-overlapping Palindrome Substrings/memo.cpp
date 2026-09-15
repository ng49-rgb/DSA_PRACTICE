#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> pal;
    vector<int> memo;

    int solve(int i, string &s, int k) {
        if (i >= n) return 0;
        if (memo[i] != -1) return memo[i];

        // Not take
        int notTake = solve(i + 1, s, k);
        // Take: choose a palindrome starting at i
        int take = 0;

        for (int j = i + k - 1; j < n; j++) {
            if (pal[i][j]) {
                take = max(take, 1 + solve(j + 1, s, k));
            }
        }
        return memo[i] = max(take, notTake);
    }

    int maxPalindromes(string s, int k) {
        n = s.size();
        // pal[i][j] = 1 if s[i...j] is a palindrome
        pal.assign(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = 1;
                }
            }
        }
        memo.assign(n, -1);
        return solve(0, s, k);
    }
};