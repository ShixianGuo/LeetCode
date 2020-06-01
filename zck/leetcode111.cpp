/*给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],
*/

#include <iostream>
#include <vector>

using namespace  std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root){
    if(!root)
        return 0;
    if(root->left && root->right)
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    if(root->left)
        return minDepth(root->left) + 1;
    else
        return minDepth(root->right) + 1;
}
 