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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, preorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root, int begin, int end) {
        if(begin > end) return NULL;
        int i = begin;
        while(i <= end && inorder[i] != preorder[root]) i++;
        TreeNode* tree = new TreeNode(preorder[root]);
        tree->left = build(preorder, inorder, root + 1, begin, i - 1);
        tree->right = build(preorder, inorder, root + i - begin + 1, i + 1, end);
        return tree;
    }
};
