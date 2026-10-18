#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    ll MOD = 1e9 + 7;

    vector<vector<ll>> PT;

    int solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        ll ways = PT[n - 1][left.size()]; // ncr where n = n-1, r = left.size or right.size()

        ways = (ways * solve(left)) % MOD; // x
        ways = (ways * solve(right)) % MOD; // y

        return ways; // z = (z * x * y) -1
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        PT.resize(n + 1); // pascal triangle 

        // Populate Pascal's Triangle
        for (int i = 0; i <= n; i++) {
            PT[i] = vector<ll>(i + 1, 1);

            for (int j = 1; j < i; j++) { // ensure loop from j=1 to less than i as last elmnt is itslef 1. 
                PT[i][j] = (PT[i - 1][j - 1] + PT[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 ) % MOD;
    }
};