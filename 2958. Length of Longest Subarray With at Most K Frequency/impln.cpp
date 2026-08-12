#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;

            if (mpp[nums[right]] > k) {
                while (mpp[nums[right]] > k) {
                    mpp[nums[left]]--;
                    left++;
                }
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2, 3, 1, 4, 2};
    int k = 2;
    int result = solution.maxSubarrayLength(nums, k);
    cout << "Maximum length of subarray with at most " << k << " occurrences of any number: " << result << endl;
    return 0;
}