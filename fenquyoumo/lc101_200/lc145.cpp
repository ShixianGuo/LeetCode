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
    vector<int > ans;
    void deal(TreeNode* root)
    {
        if(root==NULL) return ;
        if(root->left!=NULL)
        {
            deal(root->left);
        }
        if(root->right!=NULL)
        {
            deal(root->right);
        }
        ans.push_back(root->val);
        return ;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        deal(root);
        return ans;
    }
};