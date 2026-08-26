#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int j = 0;
        int cnt = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {
            // Add current character
            if (s[i] == '1') {
                cnt++;
            }

            // Shrink window while it has more than k ones
            while (cnt > k) {
                if (s[j] == '1') {
                    cnt--;
                }
                j++;
            }

            // We have exactly k ones
            if (cnt == k) {
                // Remove leading zeros
                while (s[j] == '0') {
                    j++;
                }

                string curr = s.substr(j, i - j + 1);

                // Choose shortest, and lexicographically smaller if same length
                if (ans == "" || curr.length() < ans.length() || (curr.length() == ans.length() && curr < ans)) {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};