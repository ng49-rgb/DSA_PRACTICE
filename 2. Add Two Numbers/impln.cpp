#include <bits/stdc++.h> 
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* t1 = l1;
        ListNode* t2 = l2;

        // Dummy node helps us build the answer list
        ListNode* dummyNode = new ListNode(-1);

        // Start curr at the dummy node
        ListNode* curr = dummyNode;

        int carry = 0;

        while (t1 != NULL || t2 != NULL) {

            int sum = carry;

            if (t1 != NULL) {
                sum += t1->val;
                t1 = t1->next;
            }

            if (t2 != NULL) {
                sum += t2->val;
                t2 = t2->next;
            }

            // Current digit
            ListNode* newNode = new ListNode(sum % 10);

            // Carry for the next position
            carry = sum / 10;

            // Attach the new node
            curr->next = newNode;

            // Move curr forward
            curr = curr->next;
        }

        // If a carry remains, add it
        if (carry != 0) {
            curr->next = new ListNode(carry);
        }

        return dummyNode->next;
    }
};