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
  int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxPathHelper(root, ans);
    return ans;
  }
  int maxPathHelper(TreeNode* root, int& path) {
    if (root == nullptr) return 0;
    int left = maxPathHelper(root->left, path);
    int right = maxPathHelper(root->right, path);
    int max1 = root->val + max(0, left) + max(0, right);
    int max2 = root->val + max(0, max(left, right));
    path = max(path, max(max1, max2));
    return max2;
  }
};
