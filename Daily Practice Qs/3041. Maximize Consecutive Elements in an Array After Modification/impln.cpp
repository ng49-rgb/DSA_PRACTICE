#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);

        if(j < n && nums[j] == target) {
            return j;
        }

        return -1;
    }

    int solve(int i, int inc, vector<int>& nums) {
        if(i >= n) return 0;

        if(memo[i][inc] != -1) return memo[i][inc];

        int currVal = nums[i] + inc; // inc = 0/1
        int len = 1;

        // 1st Option: Find currVal + 1 without incrementing
        int j = findMethod(nums, i + 1, currVal + 1);

        if(j != -1) {
            len = max(len, 1 + solve(j, 0, nums));
        }

        // 2nd Option: Find currVal and increment it by 1
        j = findMethod(nums, i + 1, currVal);

        if(j != -1) {
            len = max(len, 1 + solve(j, 1, nums));
        }

        return memo[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        n = nums.size();
        memo.assign(n, vector<int>(2, -1));

        int ans = 0;

        for(int i = 0; i < n; i++) {// check every index
            ans = max(ans, solve(i, 0, nums));
            ans = max(ans, solve(i, 1, nums));
        }

        return ans;
    }
};