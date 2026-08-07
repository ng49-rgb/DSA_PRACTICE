#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};


class Solution {
private:
    void add_to_lst(vector<pair<int,int>>& lst, int value) {
        for (auto &p : lst) {
            if (p.first == value) {
                p.second++;
                return;
            }
        }
        lst.push_back({value, 1});
    }

public:
    Node* flatten(Node* head) {

        vector<pair<int,int>> lst;

        Node* temp = head;

        while (temp != nullptr) {

            Node* down = temp;

            while (down != nullptr) {
                add_to_lst(lst, down->data);
                down = down->bottom;
            }

            temp = temp->next;
        }

        sort(lst.begin(), lst.end());

        Node* dummy = new Node(-1);
        temp = dummy;

        for (auto &p : lst) {
            while (p.second--) {
                temp->bottom = new Node(p.first);
                temp = temp->bottom;
            }
        }

        Node* newHead = dummy->bottom;
        delete dummy;

        return newHead;
    }
};

int main() {
    // Example usage:
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution sol;
    Node* flattenedList = sol.flatten(head);

    // Print the flattened list
    while (flattenedList != nullptr) {
        cout << flattenedList->data << " ";
        flattenedList = flattenedList->bottom;
    }

    return 0;
}