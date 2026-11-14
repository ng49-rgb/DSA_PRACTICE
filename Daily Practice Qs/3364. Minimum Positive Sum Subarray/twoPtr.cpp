#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        int n = nums.size();

        for(int len = l; len <= r; len++) {
            int i = 0, j = 0;
            int currSum = 0;

            while(j < n) {
                currSum += nums[j];

                if(j - i + 1 == len) {
                    if(currSum > 0) {
                        minSum = min(minSum, currSum);
                    }

                    currSum -= nums[i];
                    i++;
                }

                j++;
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};