#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        
        // {deadline, profit}
        vector<pair<int, int>> jobs;
        
        for(int i=0; i<n; i++){
            jobs.push_back({deadline[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        
        int maxDeadLine = 0;
        for(int i=0; i<n; i++){
            maxDeadLine = max(maxDeadLine, deadline[i]);
        }
        
        vector<int> slot(maxDeadLine+1, -1);
        
        int cnt=0, maxProfit = 0;
        
        for(int i=0; i<n; i++){// becoz we need in desc order so take from job 
        
            int d = jobs[i].first;
            int p = jobs[i].second;
            
            for(int j=d; j>=1; j--){
                if(slot[j] == -1) {
                    slot[j] = i;
                    cnt++;
                    maxProfit += p;
                    
                    break;
                }
            }
        }
        
        return {cnt, maxProfit};
    }
};