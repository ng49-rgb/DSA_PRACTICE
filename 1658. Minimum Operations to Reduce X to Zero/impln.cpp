#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for(int num : nums) total += num;

        int target = total - x;

        // Need to remove everything
        if(target == 0) return n;

        int i = 0, j = 0;
        int sum = 0;
        int maxLen = -1;

        while(j < n) {
            sum += nums[j];

            while (i <= j && sum > target) {
                sum -= nums[i];
                i++;
            }

            if(sum == target) {
                maxLen = max(maxLen, j - i + 1);
            }

            j++;
        }

        if(maxLen == -1) return -1;

        return n - maxLen;
    }
};