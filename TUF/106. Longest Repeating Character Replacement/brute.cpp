#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen = 0;
    int characterReplacement(string s, int k) {
        for(int i=0; i<s.size(); i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;

            for(int j=i; j<s.size(); j++) {
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);

                // Changes required > k
                if((j - i + 1) - maxFreq > k) {
                    break;
                }

                maxLen = max(maxLen, j - i + 1);
            }
        }
       
        return maxLen;
    }
};