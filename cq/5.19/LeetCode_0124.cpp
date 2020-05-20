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
    int traverse(TreeNode* root,int &res){
        if(!root) return 0;
        int left=traverse(root->left,res);
        int right=traverse(root->right,res);
        int maxPathSum=root->val+max(0,left)+max(0,right);
        res=max(res,maxPathSum);
        return root->val+max(0,max(left,right));
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        traverse(root,res);
        return res;
    }
};