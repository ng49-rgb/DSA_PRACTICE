#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubstrings(string s){
        long long ans = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            int mask = 0;
            for(int j=i; j<n; j++){
                mask ^= (1<<s[j]-'a');

                if(mask == 0 || (mask & (mask-1)) == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s;
    cin >> s;
    cout << sol.countSubstrings(s) << endl; 
    return 0;
}