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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int cnt =0;
        ListNode* temp = head;
        
        if(head == nullptr || head->next == nullptr) return NULL;

        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }

        if(cnt==n){
            ListNode* newHead = head->next;
            return newHead;
        }

        int res = cnt-n;
        temp = head;

        while(temp!=NULL){
            res--;
            if(res==0) break;

            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int n = 2; // Remove the 2nd node from the end
    ListNode* newHead = sol.removeNthFromEnd(head, n);

    // Print the modified list
    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}
