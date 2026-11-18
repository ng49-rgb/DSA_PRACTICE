#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        char currentChar = s[0];
        int count = 0;
        int changes = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == currentChar) {
                count++;
                continue;
            }

            // If we have even count of characters, start new sequence
            if (count % 2 == 0) {
                count = 1;
            }
            // If odd count, we need to change current character to match previous sequence
            else {
                count = 0;
                changes++;
            }

            // Update current character for next iteration
            currentChar = s[i];
        }

        return changes;
    }
};