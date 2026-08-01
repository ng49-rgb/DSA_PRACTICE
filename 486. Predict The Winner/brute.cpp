class Solution {
public:
    int maxDiff(vector<int>& nums, int i, int j) {
        // Base case: only one element left
        if (i == j) {
            return nums[i];
        }
        
        // Option 1: Take the left element
        int takeLeft = nums[i] - maxDiff(nums, i + 1, j);
        
        // Option 2: Take the right element
        int takeRight = nums[j] - maxDiff(nums, i, j - 1);
        
        // Return the best choice for the current player
        return max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        // Player 1 wins if the max difference is >= 0
        return maxDiff(nums, 0, nums.size() - 1) >= 0;
    }
};
