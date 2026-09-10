#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<int, int> solve(TreeNode* root, int &ans) {
        if (root == NULL) {
            return {0, 0};   // {sum, count}
        }

        // Get sum and count of left subtree
        pair<int, int> left = solve(root->left, ans);

        // Get sum and count of right subtree
        pair<int, int> right = solve(root->right, ans);

        // Current subtree
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;

        // Average = sum / count
        if (root->val == sum / cnt) {
            ans++;
        }

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};