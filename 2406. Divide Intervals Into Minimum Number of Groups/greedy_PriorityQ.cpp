#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        /* The minimum number of groups we need is equivalent to the 
        maximum number of intervals that overlap at some point */

        for (int i = 0; i < n; i++) {
            if (!pq.empty() && pq.top() < intervals[i][0]) {
                pq.pop();
            }

            pq.push(intervals[i][1]);
        }

        return pq.size();
    }
};