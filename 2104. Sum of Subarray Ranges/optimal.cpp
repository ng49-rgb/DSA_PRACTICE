#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nge(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        return ans;
    }

    vector<int> pgee(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        return ans;
    }

    vector<int> nse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        return ans;
    }

    vector<int> psee(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextGreater = nge(nums);
        vector<int> prevGreater = pgee(nums);

        vector<int> nextSmaller = nse(nums);
        vector<int> prevSmaller = psee(nums);

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            // Number of subarrays where nums[i] is maximum
            long long leftMax = i - prevGreater[i];
            long long rightMax = nextGreater[i] - i;
            // Number of subarrays where nums[i] is minimum
            long long leftMin = i - prevSmaller[i];
            long long rightMin = nextSmaller[i] - i;

            sum += (long long)nums[i] * leftMax * rightMax;
            sum -= (long long)nums[i] * leftMin * rightMin;
        }

        return sum;
    }
};