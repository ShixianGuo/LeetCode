/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution   
{
    TreeNode *buildTree(vector<int> &preorder, int preL, int preR, vector<int> &inorder, int inL, int inR)
    {
        TreeNode *root = new TreeNode(preorder[preL]);
        int inroot;
        for (int i = inL; i <= inR; ++i)
            if (inorder[i] == root->val)
            {
                inroot = i;
                break;
            }
        int leftLen=inroot-inL;
        int preLEnd=preL+leftLen;
        if (inL <inroot)
            root->left = buildTree(preorder, preL + 1, preLEnd, inorder, inL, inroot-1);
        if (inroot < inR)
            root->right = buildTree(preorder, preLEnd+1, preR, inorder, inroot+1, inR);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
            return nullptr;
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};