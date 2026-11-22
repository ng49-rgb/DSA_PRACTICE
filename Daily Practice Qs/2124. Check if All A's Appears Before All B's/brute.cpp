#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a') continue;
            if(s[i]=='b'){
                if(s[i+1]=='a') return false;
            }
        }
        return true;
    }
};