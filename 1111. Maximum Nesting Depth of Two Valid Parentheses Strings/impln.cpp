#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int dep = 0; // to maintain the depth
        vector<int> ans;

        for(char i=0; i<seq.size(); i++){
            if (seq[i] == '('){
                dep++;
                ans.push_back(dep % 2); // as to get as min maxDepth as possible by maxdepth / 2;
            } else {
                ans.push_back(dep % 2);
                dep--;
            }
        }

        return ans;
    }
};