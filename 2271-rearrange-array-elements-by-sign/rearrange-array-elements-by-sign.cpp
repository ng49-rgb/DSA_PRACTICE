class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> posArr;
        vector<int> negArr;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                negArr.push_back(nums[i]);
            else
                posArr.push_back(nums[i]);
        }

        for (int j = 0; j < n / 2; j++) {
            nums[2 * j] = posArr[j];
            nums[2 * j + 1] = negArr[j];
        }
        
        return nums;
    }
};