#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char c : s) {
            if(c == '(') {
                st.push(0);
            }
            else {
                int curr = st.top();
                st.pop();

                int score = max(2 * curr, 1);
                st.top() += score;
            }
        }

        return st.top();
    }
};