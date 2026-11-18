#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int changes = 0;
    int minChanges(string s) {
        int n = s.size();
        for(int i=0; i<n; i=i+2){
            if(s[i] != s[i+1]) changes++;
        }
        return changes;
    }
};