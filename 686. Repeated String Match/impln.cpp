#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int repeat = 1;
        string temp = a;
        
        // Repeat 'a' until its length is at least the length of 'b'
        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }
        
        // Check if 'b' is a substring of the current 'temp'
        if (KMP_MATCH(temp, b)) return repeat;
        
        // If not matched, try repeating 'a' one more time
        temp += a;
        if (KMP_MATCH(temp, b)) return repeat + 1;
        
        return -1;
    }

private:
    bool KMP_MATCH(const string& text, const string& pattern) {
        int m = pattern.size();
        int n = text.size();
        if (m == 0) return true;
        
        // 1. Build the LPS (Longest Prefix Suffix) table for the pattern
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // 2. Perform the KMP matching process
        i = 0; // index for text
        int j = 0; // index for pattern
        
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            
            if (j == m) {
                return true; // Full pattern match found
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    string a = "abcd";
    string b = "cdabcdab";
    int result = solution.repeatedStringMatch(a, b);
    cout << "Minimum repetitions needed: " << result << endl; // Output: 3
    return 0;
}