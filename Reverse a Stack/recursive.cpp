#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void insert(stack<int>& st, int temp) {
        // Base case: stack empty hai
        if (st.empty()) {
            st.push(temp);
            return;
        }
        
        int x = st.top();
        st.pop();
        
        insert(st, temp);
        st.push(x);
    }

    void reverseStack(stack<int>& st) {
        // Base case
        if (st.empty()) {
            return;
        }
        
        int temp = st.top();
        
        st.pop();
        // Baaki stack reverse karo
        reverseStack(st);
        
        // Current element ko bottom mein daalo
        insert(st, temp);
    }
};