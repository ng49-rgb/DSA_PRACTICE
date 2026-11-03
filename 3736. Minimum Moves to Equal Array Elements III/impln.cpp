#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int total = 0;
        int mx = *max_element(nums.begin(), nums.end());
        for(auto it : nums){
            total += mx - it;
        }
        return total;
    }
};

int main(){
    Solution sol;
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << sol.minMoves(nums) << endl;
    return 0;
}