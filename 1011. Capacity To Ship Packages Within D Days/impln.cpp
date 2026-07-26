int noOfDays(vector<int>& weights, int cap){
    int load = 0;
    int days_req = 1;
    for(auto x : weights){
        if(load + x > cap){
            days_req = days_req + 1;
            load = x; // if exceeds limit load it on the next day.
        }
        else{ // load it on the same day.
            load += x;
        }
    }
    return days_req;
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(noOfDays(weights, mid) <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};