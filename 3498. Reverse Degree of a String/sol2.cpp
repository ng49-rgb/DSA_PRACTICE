#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=1; i<=s.size(); i++){
            sum += ('z'- s[i-1] + 1) * i;
        }
        return sum;
    }
};