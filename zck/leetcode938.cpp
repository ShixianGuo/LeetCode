#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int rangeSumBST(TreeNode* root, int L, int R){
    if(!root)
        return 0;
    if(root->val >= L && root->val <= R)
        return rangeSumBST(root->left, L, R) + root->val + rangeSumBST(root->right, L, R);
    else
        return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    
    
}