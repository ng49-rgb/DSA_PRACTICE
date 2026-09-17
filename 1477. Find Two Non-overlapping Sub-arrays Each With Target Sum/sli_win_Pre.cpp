#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> prefix(n, INF);
        vector<int> suffix(n, INF);

        // prefix[i] = minimum length of a valid subarray
        // completely inside [0...i]
        int left = 0;
        int sum = 0;
        int best = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;
                best = min(best, len);
            }

            prefix[right] = best;
        }

        // suffix[i] = minimum length of a valid subarray
        // completely inside [i...n-1]
        left = n - 1;
        sum = 0;
        best = INF;

        for (int right = n - 1; right >= 0; right--) {
            sum += arr[right];

            while (sum > target && left >= right) {
                sum -= arr[left];
                left--;
            }

            if (sum == target) {
                int len = left - right + 1;
                best = min(best, len);
            }

            suffix[right] = best;
        }

        // Combine two non-overlapping subarrays
        int ans = INF;

        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] != INF && suffix[i + 1] != INF) {
                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }

        return ans == INF ? -1 : ans;
    }
};