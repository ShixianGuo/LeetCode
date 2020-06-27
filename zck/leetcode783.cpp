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
    void inOrder(TreeNode* root){
        if(root == NULL)
            return;
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
    int minDiffInBST(TreeNode* root){
        inOrder(root);
        int min_gap = INT32_MAX;
        for(int i = 1; i < res.size(); i++){
            min_gap = min(min_gap, res[i] - res[i - 1]);
        }
        return min_gap;
    }
private:
    vector<int> res;
};