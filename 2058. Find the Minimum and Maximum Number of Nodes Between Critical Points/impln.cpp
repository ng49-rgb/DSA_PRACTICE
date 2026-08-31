#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;
        int first = -1;
        int last = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        while (curr->next != nullptr) {
            // local minima OR local maxima
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                // first critical point
                if (first == -1) {
                    first = pos;
                }

                // distance between consecutive critical points
                if (last != -1) {
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        // Need at least 2 critical points
        if (first == -1 || first == last)
            return {-1, -1};

        // Maximum distance = first critical point to last critical point
        maxDist = last - first;

        return {minDist, maxDist};
    }
};