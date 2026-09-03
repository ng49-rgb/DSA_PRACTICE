#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;

        for(int i = 0; i < nums1.size(); i++) {
            mn = min(mn, nums1[i]);
        }

        // if minimum is even,every element must already be even
        if(mn % 2 == 0) {
            for(int i = 0; i < nums1.size(); i++) {
                if(nums1[i] % 2 != 0) {
                    return false;
                }
            }
        }

        return true;
    }
};