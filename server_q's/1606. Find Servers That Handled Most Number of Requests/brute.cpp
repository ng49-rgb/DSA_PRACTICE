#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> ans;
        int n = arrival.size();

        vector<int> currTime(k, 0);
        vector<int> cnt(k, 0);

        for(int i = 0; i < n; i++) {
            int serverId = i % k;
            bool assigned = false;

            for(int j = 0; j < k; j++) {
                int id = (serverId + j) % k;

                if(currTime[id] <= arrival[i]) {
                    // Assign request
                    currTime[id] = arrival[i] + load[i];
                    cnt[id]++;

                    assigned = true;
                    break;
                }
            }
        }

        int maxi = *max_element(cnt.begin(), cnt.end());

        for(int i = 0; i < k; i++) {
            if(cnt[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};