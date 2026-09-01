#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        vector<int> res;
        int n = arr.size();
        
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            
            if(st.empty()) res.push_back(-1);
            
            else{
                res.push_back(st.top());
            }
            
            st.push(arr[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};