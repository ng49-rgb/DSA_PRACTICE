#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;

        for(auto &it : knowledge) {
            mpp[it[0]] = it[1]; // does key -> value mapping
        }

        int n = s.size();
        string ans = "";
        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                int j = s.find(')', i+1); // find the index of closing bracket
                string key = s.substr(i+1, j-i-1); // extract the key between brackets

                if(mpp.find(key) != mpp.end()) {
                    ans += mpp[key]; 
                } else {
                    ans += "?"; 
                }

                i = j; 

            } else {
                ans += s[i]; 
            }
            i++;   
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = {{"name", "bob"}, {"age", "two"}};
    string result = solution.evaluate(s, knowledge);
    cout << result << endl; // Output: bobistwoyearsold
    return 0;
}