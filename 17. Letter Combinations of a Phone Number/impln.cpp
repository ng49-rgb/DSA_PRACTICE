#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(string digits, string temp, unordered_map<char,string> mpp, vector<string>& res, int indx){
        if(indx >= digits.size()){
            res.push_back(temp);
            return;
        }

        char ch = digits[indx];
        string str = mpp[ch];

        for(int i=0; i<str.size(); i++){
            temp.push_back(str[i]);

            solve(digits, temp, mpp, res, indx+1);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0)return {};
        vector<string> res;
        string temp = "";
        unordered_map<char,string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        solve(digits, temp, mpp,res, 0);
        return res;  
    }
};