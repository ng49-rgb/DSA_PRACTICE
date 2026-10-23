#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                ans = ans & i;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 3, 2, 1};
    int result = solution.sortPermutation(nums);
    cout << "Result: " << result << endl;
    return 0;
}