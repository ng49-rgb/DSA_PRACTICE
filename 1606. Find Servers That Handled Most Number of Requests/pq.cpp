#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k, 0);
        vector<int> ans;

        // {available_time, server_id}
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        set<int> available;

        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        for(int i = 0; i < arrival.size(); i++) {
            // Free servers whose work is completed
            while(!pq.empty() && pq.top().first <= arrival[i]) {
                available.insert(pq.top().second);
                pq.pop();
            }

            if(available.empty()) continue;

            int serverId = i % k;

            // Find first available server >= serverId
            auto it = available.lower_bound(serverId);

            // Circular wrap-around
            if(it == available.end()) {
                it = available.begin();
            }

            int id = *it;

            available.erase(it);

            cnt[id]++;

            pq.push({arrival[i] + load[i], id});
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