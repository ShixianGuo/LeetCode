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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack1, stack2;
        if(root) {
            stack1.push(root);
        } else {
            return res;
        }
        while(!stack1.empty()) {
            TreeNode* cur = stack1.top(); stack1.pop();
            stack2.push(cur);
            if(cur->left) stack1.push(cur->left);
            if(cur->right) stack1.push(cur->right);
        }
        while(!stack2.empty()) {
            res.push_back(stack2.top()->val);
            stack2.pop();
        }
        return res;
    }
};
