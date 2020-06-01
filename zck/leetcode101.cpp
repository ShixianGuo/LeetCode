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
    bool helper(TreeNode *p, TreeNode *q){
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        return p->val == q->val && helper(p->left, q->right) && helper(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};