#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            long long sum = 0;

            for(int j = i; j < n; j++) {
                sum += arr[j];

                if(sum % 2 != 0) {
                    cnt++;
                }
            }
        }

        return cnt % mod;
    }
};