#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int sum = 0;
            int num = nums[i];

            while(num > 0){
                sum += num % 10;
                num /= 10;
            }

            if(i == sum) return i;

        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = solution.smallestIndex(nums);
    cout << "The smallest index is: " << result << endl;
    return 0;
}