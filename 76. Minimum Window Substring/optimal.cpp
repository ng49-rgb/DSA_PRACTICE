#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), m = t.size(), i=0, j=0, cnt=0, minLen = INT_MAX, startIdx = -1;
        vector<int> hash(256,0);

        for(int i=0; i<m; i++) hash[t[i]]++;

        while (j < n){
            if(hash[s[j]] > 0) cnt++;
            hash[s[j]]--;//insert

            while(cnt == m){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    startIdx = i;
                }
                // remove
                hash[s[i]]++;
                if(hash[s[i]] > 0) cnt--;

                i++;
            }

            j++;
        }

        return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
    }
};