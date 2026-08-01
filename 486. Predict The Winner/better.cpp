class Solution {
public:
    int maxDiff(vector<int>& nums, int i, int j, vector<vector<int>>& memo) {
        // Base case: only one element left
        if (i == j) {
            return nums[i];
        }
        
        // Return cached result if already calculated
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        // Option 1: Take left element
        int takeLeft = nums[i] - maxDiff(nums, i + 1, j, memo);
        
        // Option 2: Take right element
        int takeRight = nums[j] - maxDiff(nums, i, j - 1, memo);
        
        // Cache and return the best choice
        return memo[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // Initialize a 2D memoization table with -1
        vector<vector<int>> memo(n, vector<int>(n, -1));
        
        return maxDiff(nums, 0, n - 1, memo) >= 0;
    }
};
