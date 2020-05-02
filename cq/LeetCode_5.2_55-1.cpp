/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!(root->left)&&!(root->right)) return 1;
        int res=1;
        if(root->left) res=max(res,maxDepth(root->left)+1);
        if(root->right) res=max(res,maxDepth(root->right)+1);
        return res;
    }
};