#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    stack<TreeNode*> st;
    // reverse = false -> Normal Inorder (Left -> Root -> Right){next iterator}
    // reverse = true  -> Reverse Inorder (Right -> Root -> Left){before}
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if(!reverse) {
            pushAll(node->right);
        }
        else {
            pushAll(node->left);
        }

        return node->val;
    }

    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);

            if(reverse) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j) {
            int sum = i + j;

            if(sum == k) return true;

            else if(sum < k) {
                i = l.next();
            }
            else {
                j = r.next();
            }
        }

        return false;
    }
};