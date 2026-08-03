#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> t(n + 1, -1e9);
        int diff = solve(stoneValue, 0, t); // As Alice starts from 0.
        
        if (diff < 0) {
            return "Bob";
        } else if (diff > 0) 
            return "Alice";
        return "Tie";
    }

private:
    int solve(vector<int>& stoneValue, int i, vector<int>& t) {
        int n = stoneValue.size();
        if (n <= i) return 0;
        
        if (t[i] != -1e9) {
            return t[i];
        }
        
        int res = INT_MIN;
        res = max(res, stoneValue[i] - solve(stoneValue, i + 1, t));
        if (i + 1 < n) {
            res = max(res, stoneValue[i] + stoneValue[i + 1] - solve(stoneValue, i + 2, t));
        }
        if (i + 2 < n) {
            res = max(res, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(stoneValue, i + 3, t));
        }
        
        return t[i] = res;
    }
};
