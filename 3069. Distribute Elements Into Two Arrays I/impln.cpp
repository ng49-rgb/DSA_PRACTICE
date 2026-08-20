#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr1;
        vector<int> arr2;
        vector<int> res;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i < n; i++) {

            if(arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        // Combine arr1 + arr2
        for(int it : arr1){
            res.push_back(it);
        }

        for(int it : arr2){
            res.push_back(it);
        }

        return res;
    }
};