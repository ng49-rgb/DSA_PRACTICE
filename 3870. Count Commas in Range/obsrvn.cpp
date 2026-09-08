#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        int temp = 1000;
        while (temp <= n) {
            count += n - temp + 1;
            temp *= 1000;
        }
        return count;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = solution.countCommas(n);
    cout << "Number of commas in " << n << " is: " << result << endl;
    return 0;
}