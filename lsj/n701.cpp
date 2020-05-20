/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    // 迭代
    // if (root == nullptr) return new TreeNode(val);
    // if (val < root->val) {
    //     root->left = insertIntoBST(root->left, val);
    // } else {
    //     root->right = insertIntoBST(root->right, val);
    // }
    // return root;

    // 递归
    if (root == nullptr) return new TreeNode(val);
    TreeNode *cur = root, *pre = root;
    while (cur) {
      pre = cur;
      cur = val < cur->val ? cur->left : cur->right;
    }
    if (val < pre->val) {
        pre->left = new TreeNode(val);
    } else {
        pre->right = new TreeNode(val);
    }

    return root;
  }
};
