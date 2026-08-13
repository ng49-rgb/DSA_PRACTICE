#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<int>& candidates,int target,vector<vector<int>>& res, vector<int> temp, int i) {
        // base
        if(target == 0) {
            res.push_back(temp);
            return;
        }

        for(int j = i; j < candidates.size(); j++) {

            // skip duplicate at same recursion level
            if(j > i && candidates[j] == candidates[j-1])
                continue;

            // candidates is sorted
            if(candidates[j] > target)
                break;

            // take
            temp.push_back(candidates[j]);

            solve(candidates,target - candidates[j],res,temp,j + 1);

            // backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, res, temp, 0);

        return res;
    }
};