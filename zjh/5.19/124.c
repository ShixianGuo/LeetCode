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
    int Max = INT_MIN;
public:
    int MaxPathSum(TreeNode* root) {
        if(!root){
            return INT_MIN;
        }
        int left = MaxPathSum(root->left);
        int right = MaxPathSum(root->right);
        if(left <= 0 && right <= 0){
            int tmp = max(left, right);
            tmp = max(tmp, root->val);
            Max = max(Max, tmp);
            return root->val;
        }
        else if(left > 0 && right > 0){
            Max = max(Max, left + right + root->val);
            return max(left, right) + root->val;
        }
        else if(left > 0){
            Max = max(Max, left + root->val);
            return left + root->val;
        }
        else{
            Max = max(Max, right + root->val);
            return right + root->val;
        }
    }

    int maxPathSum(TreeNode *r){
        MaxPathSum(r);
        return Max;
    }
};
