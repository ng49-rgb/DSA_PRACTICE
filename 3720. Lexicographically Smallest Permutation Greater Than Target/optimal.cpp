#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> lower(26,0);
        for (int i = 0; i < s.size(); i++) {
            lower[s[i] - 'a']++;
            lower[target[i] - 'a']--;
        }

        // Try from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            int b = target[i] - 'a';
            lower[b]++;  // Reversal of consumption

            // Check if the prefix can fully match
            if (*min_element(lower.begin(), lower.end()) < 0) {
                continue;
            }
            // Find the smallest available character larger than b.
            for (int j = b + 1; j < 26; j++) {
                if (lower[j]) {
                    lower[j]--;
                    target[i] = 'a' + j;
                    target.resize(i + 1);
                    return target + getMinString(lower);
                }
            }
        }

        return "";
    }

    // Get the lexicographically smallest string
    string getMinString(vector<int>& lower) {
        string res;
        for (int i = 0; i < 26; i++) {
            res.append(lower[i], 'a' + i);
        }
        return res;
    }
};