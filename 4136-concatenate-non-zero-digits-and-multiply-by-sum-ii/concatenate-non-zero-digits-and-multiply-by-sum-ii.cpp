class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos;
        vector<ll> prefSum;
        vector<ll> prefNum;

        int n = s.size();

        vector<ll> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = pow10[i - 1] * 10 % MOD;

        ll num = 0;
        ll sum = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;

            int d = s[i] - '0';

            pos.push_back(i);

            sum += d;
            prefSum.push_back(sum);

            num = (num * 10 + d) % MOD;
            prefNum.push_back(num);
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if (it1 == pos.end() || it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int L = it1 - pos.begin();
            int R = (it2 - pos.begin()) - 1;

            ll digitSum = prefSum[R];
            if (L)
                digitSum -= prefSum[L - 1];

            ll x = prefNum[R];
            if (L) {
                x = (x - prefNum[L - 1] * pow10[R - L + 1] % MOD + MOD) % MOD;
            }

            ans.push_back(x * digitSum % MOD);
        }

        return ans;
    }
};