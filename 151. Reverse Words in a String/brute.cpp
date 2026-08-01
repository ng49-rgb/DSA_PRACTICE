class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        
        string word = "";
        
        // Traverse the string character by character
        for (int i = 0; i < s.size(); i++) {
            // If the character is not a space, add it to the current word
            if (s[i] != ' ') {
                word += s[i];
            } 
            // If we encounter a space and have a word collected
            else if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
        
        // Push the last word if it exists
        if (!word.empty()) {
            words.push_back(word);
        }
        
        reverse(words.begin(), words.end());
        
        // Join the words into a single string separated by spaces
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            // Add a space if it's not the last word
            if (i < words.size() - 1) {
                result += " ";
            }
        }
        
        return result;
    }
};