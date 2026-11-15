#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;

        int even = 1;  // Empty prefix
        int odd = 0;

        int parity = 0;
        int ans = 0;

        for(int x : arr) {

            parity = (parity + x) % 2;

            if(parity == 0) {
                ans = (ans + odd) % mod;
                even++;
            }
            else {
                ans = (ans + even) % mod;
                odd++;
            }
        }

        return ans;
    }
};