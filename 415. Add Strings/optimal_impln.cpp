class Solution {
public:
    string addStrings(string num1, string num2) {

        if (num1.size() < num2.size())
            swap(num1, num2);

        int n1 = num1.size();
        int n2 = num2.size();

        string ans;
        ans.reserve(n1 + 1);// optimizn

        int carry = 0;
        int i = n1 - 1;
        int j = n2 - 1;

        while (j >= 0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            carry = sum / 10;
            ans += char(sum % 10 + '0');
            i--;
            j--;
        }

        while (i >= 0) {
            int sum = (num1[i] - '0') + carry;
            carry = sum / 10;
            ans += char(sum % 10 + '0');
            i--;
        }

        if (carry)
            ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};