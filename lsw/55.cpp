class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};
