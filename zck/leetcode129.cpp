/*
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。
*/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode* root, int i){
    if(root == NULL)
        return 0;
    int tmp = 10 * i + root->val;
    if(root->left == NULL && root->right == NULL)
        return tmp;
    return helper(root->left, tmp) + helper(root->right, tmp);
}
int sumNumbers(TreeNode* root) {
    return helper(root, 0);
}