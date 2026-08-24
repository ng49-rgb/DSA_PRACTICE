#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre;
        vector<int> dp(n+1);
        partial_sum(stones.begin(), stones.end(), back_inserter(pre));

        dp[n-1] = pre[n-1];
        for(int i=n-2; i>=1; i--){
            dp[i] = max(dp[i+1], pre[i] - dp[i+1]);
        }

        return dp[1];
    }
};