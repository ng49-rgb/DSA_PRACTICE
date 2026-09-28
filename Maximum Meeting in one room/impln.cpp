#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();
        // {start, end, original index}
        vector<tuple<int,int,int>> meetings;
        
        for(int i = 0; i < n; i++) {
            meetings.push_back({s[i], f[i], i+1});
        }
        
        // Sort by ending time
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b) {
            return get<1>(a) < get<1>(b);
            
        });

        vector<int> ans;
        int lastEnd = -1;

        for(int i = 0; i < n; i++) {

            int s = get<0>(meetings[i]);
            int e = get<1>(meetings[i]);
            int idx = get<2>(meetings[i]);
            
            if(s > lastEnd) {
                ans.push_back(idx);
                lastEnd = e;
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
    }
};