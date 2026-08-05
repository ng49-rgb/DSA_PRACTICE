#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; 

class Solution {
public:
    Node* addOne(Node* head) {
        Node* temp = head;
        int carry = helper(temp);
        
        if(carry == 1){
            Node* newHead = new Node(1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }

private:
    int helper(Node* temp) { 
        if(temp == nullptr) return 1; 
        
        int carry = helper(temp->next); 
        temp->data = temp->data + carry;
        
        if(temp->data < 10) return 0;
        
        temp->data = 0;
        return 1; 
    }
};
