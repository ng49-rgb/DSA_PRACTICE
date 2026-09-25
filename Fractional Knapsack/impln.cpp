#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<pair<double, int>> ratio; // stores ratio pi/wi , indx 
        
        for(int i=0; i<n; i++){
            double r = (double) val[i] / wt[i];
            ratio.push_back({r,i});
        }
        
        sort(ratio.begin(), ratio.end(), greater<pair<double, int>>());
        
        double ans = 0;
        
        for(int i=0; i<n; i++){
            int idx = ratio[i].second;
            
            if(wt[idx] <= capacity){
                ans += val[idx];
                capacity -= wt[idx];
            }
            
            else{
                ans += ratio[i].first * capacity;
                capacity = 0;
                break;
            }
        }
        
        return ans;
    }
};