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
    Node* segregate(Node* head) {
        // code here
        Node* temp = head;
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* ones = oneHead;
        Node* twos = twoHead;
        Node* zeros = zeroHead;
        
        while(temp!=NULL){
        if(temp->data == 0){
            zeros->next = temp;
            zeros = zeros->next;
        }
        
        else if(temp->data == 1){
            ones->next = temp;
            ones = ones->next;
        }
        
        else{
            twos->next = temp;
            twos = twos->next;
        }
        temp = temp -> next;
        }
        
        zeros->next = oneHead->next?oneHead->next:twoHead->next;
        ones->next = twoHead->next;
        twos->next = NULL;
        
        Node* newHead = zeroHead->next; 
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return newHead;
    }
    
};