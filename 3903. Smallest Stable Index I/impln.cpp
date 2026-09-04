#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int maxVal = nums[i], minVal = nums[i];

            for(int j=0; j<i; j++){
                maxVal = max(maxVal, nums[j]);
            }

            for(int j=i+1; j<n; j++){
                minVal = min(minVal, nums[j]);
            }

            if(maxVal - minVal <= k) return i;
        }
        return -1;
    }
};