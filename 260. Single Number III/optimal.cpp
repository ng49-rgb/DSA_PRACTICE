#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    vector<int> singleNumber(vector<int>& nums) {
        ll xorAll = 0;

        // XOR of all elements
        for(int i = 0; i < nums.size(); i++) {
            xorAll ^= nums[i];
        }

        // Rightmost set bit
        ll rightMost = xorAll & -xorAll;// equal to (xorAll & xorAll -1 )^ xorAll

        ll b1 = 0;
        ll b2 = 0;

        // Divide elements into two buckets
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & rightMost) {
                b1 ^= nums[i];
            }
            else {
                b2 ^= nums[i];
            }
        }

        return {(int)b1, (int)b2};
    }
};