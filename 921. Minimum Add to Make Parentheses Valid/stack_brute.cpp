#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int cnt = 0;

        for(char ch : s) {
            if(ch == '(') {
                st.push(1);
            }
            else {
                if(!st.empty())
                    st.pop();
                else
                    cnt++;
            }
        }

        return cnt + st.size();
    }
};