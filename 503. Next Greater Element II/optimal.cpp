#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        // Traverse twice because the array is circular
        for (int i = 2 * n - 1; i >= 0; i--) {

            int idx = i % n;

            // Remove elements that cannot be the answer
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // Stack top is the next greater element
            if (!st.empty()) {
                res[idx] = st.top();
            }

            st.push(nums[idx]);
        }
        return res;
    }
};