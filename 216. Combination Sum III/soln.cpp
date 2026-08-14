#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int k, int n, vector<vector<int>>& ans, vector<int>& temp, int indx) {

        // Exactly k numbers selected
        if (temp.size() == k) {
            if (n == 0) {
                ans.push_back(temp);
            }
            return;
        }

        for (int i = indx; i <= 9; i++) {

            // Current number cannot be used
            if (i > n)
                break;

            // Take i
            temp.push_back(i);

            solve(k, n - i, ans, temp, i + 1);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(k, n, ans, temp, 1);

        return ans;
    }
};

int main() {
    Solution sol;
    int k = 3; // Number of elements to select
    int n = 7; // Target sum
    vector<vector<int>> result = sol.combinationSum3(k, n);

    // Print the result
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}