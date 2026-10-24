#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        unordered_map<int, int> mpp = {
            {1, 31}, {2, 28}, {3, 31}, {4, 30},
            {5, 31}, {6, 30}, {7, 31}, {8, 31},
            {9, 30}, {10, 31}, {11, 30}, {12, 31}
        };

        int Alice_1st = stoi(arriveAlice.substr(0, 2));
        int Alice_2nd = stoi(arriveAlice.substr(3, 2));

        int Alice_3rd = stoi(leaveAlice.substr(0, 2));
        int Alice_4th = stoi(leaveAlice.substr(3, 2));

        int Bob_1st = stoi(arriveBob.substr(0, 2));
        int Bob_2nd = stoi(arriveBob.substr(3, 2));

        int Bob_3rd = stoi(leaveBob.substr(0, 2));
        int Bob_4th = stoi(leaveBob.substr(3, 2));

        auto toDays = [&](int month, int day) {
            int total = day;
            for (int i = 1; i < month; i++) {
                total += mpp[i];
            }
            return total;
        };

        int start = max(toDays(Alice_1st, Alice_2nd),toDays(Bob_1st, Bob_2nd));

        int end = min(toDays(Alice_3rd, Alice_4th), toDays(Bob_3rd, Bob_4th));

        return max(0, end - start + 1);
    }
};