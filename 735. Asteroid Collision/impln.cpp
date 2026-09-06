#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int val : asteroids) {
            // Negative asteroid can collide with positive asteroid
            while (!st.empty() && st.top() > 0 && val < 0) {

                if (st.top() < abs(val)) {
                    // Top positive asteroid is destroyed
                    st.pop();
                }
                else if (st.top() == abs(val)) {
                    // Both are destroyed
                    st.pop();
                    val = 0;
                    break;
                }
                else {
                    // Current negative asteroid is destroyed
                    val = 0;
                    break;
                }
            }

            // If current asteroid survived, push it
            if (val != 0) {
                st.push(val);
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};