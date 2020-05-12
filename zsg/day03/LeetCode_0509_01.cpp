#include <bits/stdc++.h>
using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return (maxDepth(root->left) > maxDepth(root->right)) ? 1 + maxDepth(root->left) : 1 + maxDepth(root->right);
    }
};