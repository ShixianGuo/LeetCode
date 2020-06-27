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
    TreeNode* next = NULL;
    TreeNode* convertBiNode(TreeNode* root){
        if(root == NULL)
            return NULL;
        convertBiNode(root->right);
        root->right = next;
        next = root;
        convertBiNode(root->left);
        root->left = NULL;
        return next;
    }
};