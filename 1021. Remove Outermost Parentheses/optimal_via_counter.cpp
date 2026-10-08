class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans ="";
        int counter = 0;

        for(int i=0; i<s.size(); i++){
            
            if(s[i] == ')') counter--;

            if(counter != 0) ans.push_back(s[i]);

            if(s[i] == '(') counter++;
        }

        return ans;
    }
};
// another approach is stack based :
// if ( s[i] == '(') {
//     if (!stk.empty()) ans.push_back(s[i]);
//     stk.push('(');
// } else {
//     stk.pop();
//     if (!stk.empty()) ans.push_back(s[i]);
// }