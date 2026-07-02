class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            // if((sum > maxi){
            //     maxi = sum
            // } OR

            maxi = max(sum, maxi);

            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};