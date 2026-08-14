#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {

        int maxLen = 0;

        int j = 0;
        int n = s.length();

        vector<int> hmpp(26, 0);

        for(int i = 0; i < n; i++) {

            // Add current character
            hmpp[s[i] - 'a']++;

            // If current character occurs more than 2 times
            while(hmpp[s[i] - 'a'] > 2) {

                hmpp[s[j] - 'a']--;
                j++;
            }

            maxLen = max(maxLen, i - j + 1);
        }

        return maxLen;
    }
};