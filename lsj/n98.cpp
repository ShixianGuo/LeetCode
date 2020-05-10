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
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(!stack.empty() || cur) {
            while(cur) {
                stack.push(cur);
                cur = cur->left;
            }
            TreeNode* node = stack.top(); stack.pop();
            if(pre >= node->val) return false;
            pre = node->val;
            if(node->right) cur = node->right;
        }
        return true;
        // if(!root) return true;
        // if(!isValidBST(root->left)) return false;
        // if(pre >= root->val) return false;
        // pre = root->val;
        // return isValidBST(root->right);
    }
};
