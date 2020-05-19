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
    int ans=INT_MIN;
    int maxps(TreeNode* root){
        if(root==NULL) return 0;
        int leftsum=max(maxps(root->left),0);
        int rightsum=max(maxps(root->right),0);
        int newpath=leftsum+root->val+rightsum;
        ans=max(ans,newpath);
        return root->val+max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        maxps(root);
        return ans;
    }
};