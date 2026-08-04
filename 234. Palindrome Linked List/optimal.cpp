#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 1. find the middle
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //2. reverse the slow->next
        ListNode* newHead = reverse(slow->next);

        //3. compare
        ListNode* first = head;
        ListNode* second = newHead;

        while(second != NULL){
            if(first->val != second->val){
                reverse(newHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverse(newHead);
        return true;
    }

private:
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* front = nullptr;

        while(temp!=nullptr){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    
};