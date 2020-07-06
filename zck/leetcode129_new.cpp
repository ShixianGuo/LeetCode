#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode* root, int val){
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
        return root->val + 10 * val;
    return helper(root->left, root->val + 10 * val) + helper(root->right, root->val + 10 * val); 
}
int sumNumbers(TreeNode* root){
    return helper(root, 0);
}