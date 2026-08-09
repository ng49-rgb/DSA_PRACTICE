#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    struct Node {
        string url;
        Node* back;
        Node* forward;

        Node(string url) {
            this->url = url;//this is a ptr to current class member / object
            back = nullptr;
            forward = nullptr;
        }
    };

    Node* curr;

    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->forward = newNode;
        newNode->back = curr;
        curr = newNode; 
    }
    
    string forward(int steps) {
        while(steps){
            if(curr->forward) curr=curr->forward;
            else break;
            steps--;
        }
        return curr->url;
    }
    
    string back(int steps) {
        while(steps){
            if(curr->back) curr=curr->back;
            else break;
            steps--;
        }
        return curr->url;
    }
};

int main() {
    BrowserHistory* obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");
    cout << obj->back(1) << endl; // facebook.com
    cout << obj->back(1) << endl; // google.com
    cout << obj->forward(1) << endl; // facebook.com
    obj->visit("linkedin.com");
    cout << obj->forward(2) << endl; // linkedin.com
    cout << obj->back(2) << endl; // google.com
    cout << obj->back(7) << endl; // leetcode.com
    return 0;
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */