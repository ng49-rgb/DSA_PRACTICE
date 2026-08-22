#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sumDigs=0, product=1;
        int temp = n;

        while(temp > 0){
        int digit = temp % 10;
        sumDigs += digit;
        product *= digit;
        temp /= 10;
        }

        int sum = sumDigs + product;
        
        return n % sum == 0;
    }
};