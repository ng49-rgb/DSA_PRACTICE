#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        int indx = 0;
        string ans;

        while(indx < address.size()){

            if(address[indx]=='.'){
                ans +="[.]";
            }

            else ans += address[indx];
            indx++;
        }
        return ans;
    }
};