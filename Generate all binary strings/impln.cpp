#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void generate(int n, string curr, vector<string>&res){
        if(curr.length() == n){
            res.push_back(curr);
            return;
        }
        
        generate(n, curr + '0', res);
        generate(n, curr + '1', res);
    }
  
    vector<string> binstr(int n) {
        // code here
        string curr = "";
        vector<string>res;
        
        generate(n, curr, res);
        
        return res;
    }
};