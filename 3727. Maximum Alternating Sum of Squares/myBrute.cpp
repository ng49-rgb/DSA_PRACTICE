#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(),[](int a, int b) {
            return abs(a) < abs(b);
        });

        deque<pair<int, int>> dq;

        for (int i = 0; i < nums.size(); i++) {
            dq.push_back({abs(nums[i]), i});
        }

        long long ans = 0;

        while (!dq.empty()) {
            long long x = dq.back().first;
            ans += x * x;
            dq.pop_back();

            if (!dq.empty()) {
                x = dq.front().first;
                ans -= x * x;
                dq.pop_front();
            }
        }

        return ans;
    }
};