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
        if (root == nullptr)
            return 0;
        auto leftH = maxDepth(root->left);
        auto rightH = maxDepth(root->right);
        return leftH > rightH ? leftH + 1 : rightH + 1;
    }
};
