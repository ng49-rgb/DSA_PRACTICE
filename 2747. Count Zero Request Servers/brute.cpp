#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int N = queries.size();
        vector<int> ans;

        for(int i = 0; i < N; i++) {
            int cnt = 0;

            vector<int> vis(n + 1, 0);

            int start = queries[i] - x;
            int end = queries[i];

            for(int j = 0; j < logs.size(); j++) {

                if(logs[j][1] >= start && logs[j][1] <= end) {
                    vis[logs[j][0]] = 1;
                }
            }

            for(int j = 1; j <= n; j++) {
                if(vis[j] == 0) {
                    cnt++;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};