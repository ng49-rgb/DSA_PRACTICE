#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


class Solution { 
public:
    vector<int> floorCeilOfBST(TreeNode* root, int key) {
        int flr = -1, cl = -1;

        while(root != nullptr) {
            if(root->data == key) {
                flr = key;
                cl = key;
                break;
            }
            else if(root->data < key) {
                flr = root->data;// because we need as largest as possible
                root = root->right;
            }
            else {
                cl = root->data;
                root = root->left;//because we need as smallest as possible
            }
        }

        return {flr, cl};
    }
};