#include <bits/stdc++.h>
using namespace std;

class Solution { 
public: 
    int smallestNumber(int n, int t) { 
        int ans = 0; 
        for(int i = n; i < 101; i++){ 
            int temp = i;       
            int prod = 1;      
            
            while(temp > 0) {
                prod *= (temp % 10);
                temp /= 10;
            }
            
            if(prod % t == 0){ 
                ans = i; 
                break; 
            } 
        } 
        return ans; 
    } 
};