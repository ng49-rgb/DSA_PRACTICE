#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> lastSkipIdx;
        string res = "";

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                lastSkipIdx.push(res.size());
            } else if(s[i] == ')') {
                int l = lastSkipIdx.top();
                reverse(res.begin() + l, res.end());
                lastSkipIdx.pop();
            } else {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};