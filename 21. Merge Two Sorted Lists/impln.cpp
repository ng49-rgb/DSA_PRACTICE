#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Edge cases
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        // Dummy node
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;

        while (temp1 != NULL && temp2 != NULL) {

            if (temp1->val <= temp2->val) {
                curr->next = temp1;
                temp1 = temp1->next;
            }
            else {
                curr->next = temp2;
                temp2 = temp2->next;
            }

            curr = curr->next;
        }

        // Attach remaining nodes
        if (temp1 != NULL)
            curr->next = temp1;
        else
            curr->next = temp2;

        return dummyNode->next;
    }
};