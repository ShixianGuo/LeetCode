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
private:
    void postorderTraversal(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        if (root -> left != NULL)
            postorderTraversal(root -> left, ans);
        if (root -> right != NULL)
            postorderTraversal(root -> right, ans);
        ans.push_back(root -> val);
        return;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderTraversal(root, ans);
        return ans;
    }
};