class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];

        // Find sequential prefix sum
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        // Find smallest integer >= sum
        while (true) {
            bool found = false;

            for (int x : nums) {
                if (x == sum) {
                    found = true;
                    break;
                }
            }

            if (!found)
                return sum;

            sum++;
        }
    }
};