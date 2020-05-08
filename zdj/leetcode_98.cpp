class Solution {
    bool flag;
    double pre;
public:
    Solution() {
        flag = true;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* left_node = root;
        if(!left_node)
            return true;
        while(left_node->left)
            left_node = left_node->left;
        pre = (double)left_node->val - 1;
        mid(root);
        return flag;
    }

    void mid(TreeNode* root) {
        if(!root)
            return;
        mid(root->left);
        if(root->val <= pre)
            flag = false;
        pre = root->val;
        mid(root->right);
    }
};
