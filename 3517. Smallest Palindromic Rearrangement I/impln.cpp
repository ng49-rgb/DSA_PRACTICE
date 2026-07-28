class Solution {
public:
    string smallestPalindrome(string s) {
        if (s.size() == 1) return s;

        string odd = "";
        vector<int> lower(26, 0);

        // Count frequency
        for (char ch : s) {
            lower[ch - 'a']++;
        }

        string left = "";

        for (int i = 0; i < 26; i++) {
            // Store the middle character
            if (lower[i] % 2 == 1) {
                odd = char(i + 'a');
            }

            // Put half of the characters in the left half
            left += string(lower[i] / 2, char(i + 'a'));
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + odd + right;
    }
};