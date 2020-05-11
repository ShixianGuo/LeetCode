
/*
剑指offer55
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
*/

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
    //使用递归
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
    //也可以使用层序遍历
};