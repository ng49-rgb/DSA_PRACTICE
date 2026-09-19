#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mpp;

        int maxLen = -1;
        int i = 0, j = 0;
        int n = s.size();

        while (j < n) {
            mpp[s[j]]++;

            if (mpp.size() > k) {
                mpp[s[i]]--;

                if (mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }

                i++;
            }

            if (mpp.size() == k) {
                maxLen = max(maxLen, j - i + 1);
            }

            j++;
        }

        return maxLen;
    }
};