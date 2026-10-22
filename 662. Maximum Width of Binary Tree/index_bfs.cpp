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
    using ll = unsigned long long;

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        ll maxWidth = 0;

        q.push({root, 0}); //root, indx

        while(!q.empty()){
            // for each current level
            ll L = q.front().second;
            ll R = q.back().second;

            maxWidth = max(maxWidth, R-L+1);

            int n = q.size();

            while(n--){
                TreeNode* curr = q.front().first;
                ll idx = q.front().second;
                q.pop();

                if(curr -> left){
                    q.push({curr->left, 2*idx+1});
                }
                if(curr->right){
                    q.push({curr->right, 2*idx+2});
                }
            }
        } 
        return maxWidth;
    }
};