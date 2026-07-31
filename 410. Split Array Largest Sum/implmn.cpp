bool Lsum(vector<int>& nums, int barrier, int k){
    int cnt = 1; 
    int sum = 0;
    for(auto it : nums){
        if(it > barrier) return false;

        if(sum + it > barrier){
            cnt += 1;
            sum = it;
        }
        else sum += it;
    }

    if(cnt > k) return false;
    else return true;
}

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = *min_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(),0);
        int ans = -1;
        int n = nums.size();

        if(k > n) return -1;

        while(low <= high){
            long long mid = low + (high - low)/2;

            if(Lsum(nums, mid, k)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};