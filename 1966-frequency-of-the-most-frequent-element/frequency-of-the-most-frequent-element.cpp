class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0;
        int ans = 1;
        long long currSum = 0;

        for (int right = 0; right < n; right++) {
            currSum += nums[right];

            while ((long long)nums[right] * (right - left + 1) - currSum > k) {
                currSum -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};