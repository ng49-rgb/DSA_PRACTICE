class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minElIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxElIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minElIdx, maxElIdx);
        int right = max(minElIdx, maxElIdx);

        return min({
            left + 1 + n - right,  // one from each side
            right + 1,             // both from left
            n - left               // both from right
        });
    }
};