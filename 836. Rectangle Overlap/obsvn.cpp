#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& A, vector<int>& B) {
        if (A[2] <= B[0] || B[2] <= A[0] || A[3] <= B[1] || B[3] <= A[1]) {
            return false;
        }
        
        return true;
    }
};