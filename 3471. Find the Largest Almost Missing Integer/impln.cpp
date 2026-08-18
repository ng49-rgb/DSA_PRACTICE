#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;

        // Generate every subarray of size k
        for (int i = 0; i <= n - k; i++) {

            unordered_set<int> seen;

            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            // Count this element once for this subarray
            for (int x : seen) {
                cnt[x]++;
            }
        }

        int ans = -1;
        // Find largest element appearing in exactly 1 subarray
        for (auto it : cnt) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};