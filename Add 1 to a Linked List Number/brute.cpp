#include <bits/stdc++.h>
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
        // code here
        head = reverseLL(head);
        Node* temp = head;
        int carry=1;
        
        while(temp!=NULL){
            temp->data = temp->data + carry;
            if(temp->data < 10){
                carry=0;
                break;
            }
            else{
                temp->data = 0;
                carry = 1;
            }
            temp =  temp->next;
        }
        
        if(carry==1){
            head = reverseLL(head);
            Node* newHead = new Node(1);
            newHead->next = head;
            return newHead;
        }
        
        head = reverseLL(head);
        return head;
    }
    
private:
    Node* reverseLL(Node* head){
        if(head == NULL || head->next==NULL) return head;
        
        Node* newN = reverseLL(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = NULL;
        
        return newN;
    } 
    
};