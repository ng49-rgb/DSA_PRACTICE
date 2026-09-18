#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubstring(string &s) {
        // Code here
        int n = s.size(), cnt = 0;
        
        for(int i=0; i<n; i++){
            int cntA = 0, cntB = 0, cntC = 0;
            
            for(int j=i; j<n; j++){
                if(s[j] == 'a') cntA++;
                if(s[j] == 'b') cntB++;
                if(s[j] == 'c') cntC++;
                
                if(cntA >= 1 && cntB >= 1 && cntC >=1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.countSubstring(s) << endl;
    return 0;
}