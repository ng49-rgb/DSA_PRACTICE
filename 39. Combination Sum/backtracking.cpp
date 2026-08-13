#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<int>& candidates, int target,vector<vector<int>>& res,vector<int>& temp, int sum, int i) {

        // target reached
        if(sum == target) {
            res.push_back(temp);
            return;
        }

        // out of bounds or sum exceeded
        if(i >= candidates.size() || sum > target) {
            return;
        }

        // TAKE
        temp.push_back(candidates[i]);

        // i stays same because we can reuse the same number
        solve(candidates, target, res, temp,sum + candidates[i], i);

        // BACKTRACK
        temp.pop_back();

        // NOT TAKE
        solve(candidates, target, res, temp,sum, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        vector<int> temp;

        solve(candidates, target, res, temp, 0, 0);

        return res;
    }
};