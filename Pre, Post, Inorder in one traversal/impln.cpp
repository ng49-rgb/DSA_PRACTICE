#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void solveIn(TreeNode* root, vector<int>& in) {
    if (root == nullptr) return;

    solveIn(root->left, in);
    in.push_back(root->data);
    solveIn(root->right, in);
}

void solvePre(TreeNode* root, vector<int>& pre) {
    if (root == nullptr) return;

    pre.push_back(root->data);
    solvePre(root->left, pre);
    solvePre(root->right, pre);
}

void solvePost(TreeNode* root, vector<int>& post) {
    if (root == nullptr) return;

    solvePost(root->left, post);
    solvePost(root->right, post);
    post.push_back(root->data);
}

class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<vector<int>> res(3);

        solveIn(root, res[0]);
        solvePre(root, res[1]);
        solvePost(root, res[2]);

        return res;
    }
};