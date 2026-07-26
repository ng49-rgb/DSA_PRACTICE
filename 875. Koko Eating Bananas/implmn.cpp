class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int pile : piles) {
            high = max(high, pile);
        }
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canFinish(piles, mid, h)) {
                // Found a valid speed, try a slower one
                high = mid - 1;
            } else {
                low = mid + 1;     // Too slow, need a faster speed
            }
        }
        return low;
    }

private:
    bool canFinish(const vector<int>& piles, int speed, int h) {
        long long totalHours = 0;
        for(int pile : piles) {
            totalHours += (pile + speed - 1) / speed;
        }
        return totalHours <= h;
    }
};
