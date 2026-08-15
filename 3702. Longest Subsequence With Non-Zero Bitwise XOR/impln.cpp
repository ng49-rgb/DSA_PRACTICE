#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int TotalXor = 0;
        bool isNonZero = false;

        for (int i = 0; i < n; i++) {
            TotalXor ^= nums[i];
            if (nums[i] != 0) {
                isNonZero = true;
            }
        }
        if(TotalXor != 0) {
            return n;
        }
        if(isNonZero) {
            return n - 1;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 0, 4};
    int result = solution.longestSubsequence(nums);
    cout << "Length of the longest subsequence: " << result << endl;
    return 0;
}