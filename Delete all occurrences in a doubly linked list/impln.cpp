#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {

        // code here
        Node* temp = head;
        
        while(temp!=NULL){
            if(temp->data == x){
                if(temp == head){
                    head = head->next;
                }
                Node* front = temp->next;
                Node* back = temp->prev;
                
                if(front) front->prev = back;
                
                if(back) back->next = front;
                
                temp = temp->next;
            }
            
            else{
                temp = temp->next;
            }
        }
        
        return head;
    }
};

int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;

    Solution sol;
    int x = 2;
    head = sol.deleteAllOccurOfX(head, x);

    // Print the modified linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    return 0;
}