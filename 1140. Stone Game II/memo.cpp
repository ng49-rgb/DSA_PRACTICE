#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[2][101][101];

    int solveAlice(vector<int>& piles, int person, int indx, int m) {
        
        if (indx >= piles.size())
            return 0;

        if (t[person][indx][m] != -1)
            return t[person][indx][m];

        int result = (person == 1) ? -1 : INT_MAX;

        int stones = 0;
        int n = piles.size();

        for (int x = 1; x <= min(2 * m, n - indx); x++) {

            stones += piles[indx + x - 1];

            if (person == 1) {
                // Alice
                result = max(result,stones + solveAlice(piles, 0, indx + x, max(m, x)));
            }
            else {
                // Bob
                result = min( result,solveAlice(piles, 1, indx + x, max(m, x)));
            }
        }

        return t[person][indx][m] = result;
    }

    int stoneGameII(vector<int>& piles) {

        memset(t, -1, sizeof(t));

        return solveAlice(piles, 1, 0, 1);
    }
};