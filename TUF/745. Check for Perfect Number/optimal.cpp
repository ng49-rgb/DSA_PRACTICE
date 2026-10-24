#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfect(int n) {
        vector<int> vec;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i != n) vec.push_back(i);

                int other = n / i;
                if (other != i && other != n) {
                    vec.push_back(other);
                }
            }
        }

        return accumulate(vec.begin(), vec.end(), 0) == n;
    }
};

int main() {
    Solution solution;
    int n = 28; 
    if (solution.isPerfect(n)) {
        cout << n << " is a perfect number." << endl;
    } else {
        cout << n << " is not a perfect number." << endl;
    }
    return 0;
}