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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 && inorder.size()==0)
            return NULL;
        TreeNode* root = new TreeNode(sizeof(TreeNode));
        root->val= preorder[0];
        vector<int> temp_preorder_01, temp_preorder_02;
        vector<int> temp_inorder_01, temp_inorder_02;
        int i = 0;
        while (inorder[i] != root->val) {
            temp_preorder_01.push_back(preorder[i+1]);
            temp_inorder_01.push_back(inorder[i]);
            i++;
        }
        i += 2;
        while (i<preorder.size()) {
            temp_preorder_02.push_back(preorder[i]);
            temp_inorder_02.push_back(inorder[i]);
            i++;
        }
        root->left = buildTree(temp_preorder_01,temp_inorder_01);
        root->right = buildTree(temp_preorder_02,temp_inorder_02);
        return root;
    }
};

int main()
{
    vector<int> preorder= {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution ss;
    TreeNode* x = ss.buildTree(preorder,inorder);
    return 0;
}