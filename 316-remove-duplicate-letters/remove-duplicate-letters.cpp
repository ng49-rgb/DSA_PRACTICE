class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string res;
        vector<bool> taken(n,false);
        vector<int> lastIdx(26);

        for(int i = 0; i<n; i++){ // last idx
            char ch = s[i];
            lastIdx[ch - 'a'] = i;
        }

        for(int i=0; i<n; i++){
            char ch = s[i];

            int idx = ch - 'a';
            if(taken[idx] == true) continue;

            while(res.length() > 0 && res.back() > ch && lastIdx[res.back() - 'a'] > i){
                taken[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            taken[idx] = true;

        }

        return res;
    }
};