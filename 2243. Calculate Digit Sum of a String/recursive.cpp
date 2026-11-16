#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string s, int k) {
        if(s.length() <= k) return s;

        string ans = "";

        for(int i = 0; i < s.length(); i += k) {
            int sum = 0;

            for(int j = i; j < min(i + k, (int)s.length()); j++) {
                sum += s[j] - '0';
            }

            ans += to_string(sum);
        }

        return solve(ans, k);
    }

    string digitSum(string s, int k) {
        return solve(s, k);
    }
};