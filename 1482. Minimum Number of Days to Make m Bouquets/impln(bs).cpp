bool possible(vector<int>& bloomDay,int day,int m,int k){ 
    int cnt = 0; 
    int noOfB = 0; 
    for(long long x : bloomDay){ 
        // condn for already bloomed 
        if(x <= day) cnt++; 
        else{ 
            noOfB += (cnt/k); 
            cnt = 0; 
        } 
    } 
    noOfB += (cnt/k);
    if(noOfB >= m) return true; 
    else return false; 
} 

class Solution { 
public: 
    int minDays(vector<int>& bloomDay, int m, int k) { 
        int low = INT_MAX; 
        int high = INT_MIN; 
        int ans = 0; 
        for(auto x : bloomDay){ 
            low = min(low,x); 
            high = max(high,x); 
        } 
        while(low <= high){ 
            if(bloomDay.size() < (long long)m * k) return -1; 
            int mid = low + (high - low) / 2; 
            if(possible(bloomDay, mid, m, k)){ 
                ans = mid; 
                high = mid - 1; 
            } 
            else{ 
                low = mid + 1; 
            } 
        } 
        return ans; 
    }
};
