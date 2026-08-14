#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void solve(string s, vector<string>& temp, vector<vector<string>>& res, int indx) {

        // Entire string partitioned
        if (indx >= s.length()) {
            res.push_back(temp);
            return;
        }

        for (int i = indx; i < s.length(); i++) {

            // Take s[indx ... i] only if palindrome
            if (isPalindrome(s, indx, i)) {

                string part = s.substr(indx, i - indx + 1);

                temp.push_back(part);

                solve(s, temp, res, i + 1);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;
        vector<string> temp;

        solve(s, temp, res, 0);

        return res;
    }
};