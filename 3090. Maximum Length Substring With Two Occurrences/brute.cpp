#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {

        int maxLen = 0;

        int n = s.length();

        vector<int> hmpp(26, 0);

        for(int i = 0; i < n; i++) {
            
            for(int j = i; j < n; j++) {

                // Add current character
                hmpp[s[j] - 'a']++;

                // If current character occurs more than 2 times
                if(hmpp[s[j] - 'a'] > 2) {
                    break;
                }
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
}
};
