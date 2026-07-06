class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int indx = -1;

        // try to find maxm common prefix aka break pt.
        for(int i = n - 2; i >= 0; i--){
            if(nums[i + 1] > nums[i]){
                indx = i;
                break;
            }
        }

        if(indx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // try to find closest in remaining and swap it with i.
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] > nums[indx]){
                swap(nums[i], nums[indx]);
                break;
            }
        }

        // sort remaining to find the next permutation by sort or by reversing
        reverse(nums.begin() + indx + 1, nums.end());
    }
};