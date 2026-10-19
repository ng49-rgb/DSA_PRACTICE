#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lower = 0,  equals = 0;

        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] < target) {
                lower++;
            } else if (nums[i] == target) {
                equals++;
            }
        }

        vector<int> ans;
        for(int i = lower; i < lower + equals; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};