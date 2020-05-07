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
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;
        auto len = preorder.size();
        for (auto i = 0; i < len; i++)
            indexMap[inorder[i]] = i;
        auto root = buildTree(preorder, 0, len - 1, inorder, 0, len - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, int preorderStart, int preorderEnd, vector<int>& inorder, int inorderStart, int inorderEnd) {
        if (preorderStart > preorderEnd)
            return nullptr;
        auto rootVal = preorder[preorderStart];
        auto root = new TreeNode(rootVal);
        if (preorderStart == preorderEnd)
            return root;
        else {
            auto rootIndex = indexMap[rootVal];
            auto leftNodes = rootIndex - inorderStart;
            auto rightNodes = inorderEnd - rootIndex;
            auto leftSubTree = buildTree(preorder, preorderStart + 1, preorderStart + leftNodes, inorder, inorderStart, rootIndex - 1);
            auto rightSubTree = buildTree(preorder, preorderEnd - rightNodes + 1, preorderEnd, inorder, rootIndex + 1, inorderEnd);
            root->left = leftSubTree;
            root->right = rightSubTree;
            return root;
        }
    }
private:
    unordered_map<int, int> indexMap;
};
