#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int counter = 0;
        int maxCnt = 0;

        for(char i=0; i<s.size(); i++){
            if(s[i] == '('){
                counter++;
            } 
            else if(s[i] == ')') counter--;

            maxCnt = max(maxCnt, counter);
        }

        return maxCnt;
    }
};