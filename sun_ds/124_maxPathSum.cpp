// @File   : 124_maxPathSum.cpp
// @Source : https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
// @Title  : 124. 二叉树中的最大路径和
// @Auther : sun_ds
// @Date   : 2020/5/19

/**  题目描述：
    给定一个非空二叉树，返回其最大路径和。

    本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

    示例 1:

    输入: [1,2,3]

           1
          / \
         2   3

    输出: 6
    示例 2:

    输入: [-10,9,20,null,null,15,7]

       -10
       / \
      9  20
        /  \
       15   7

    输出: 42

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 后序遍历。
 * 分别得到左子树中最大路径和右子树最大路径。(注意，如果是负贡献直接置零不要了。)
 * 当前路径 = 左 + 当前 + 右
 * 返回 最大的子树路径 + 当前。
 * 使用 res 记录递归过程中的最大路径。
 *
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
    int res = INT_MIN;
    int func(TreeNode* root){
        if(root==NULL) return 0;
        //与 0 比较，负贡献就不算了。
        int left = max(func(root->left),0);
        int right = max(func(root->right),0);
        //左-中-右路径的和
        res = max(res, left+right+root->val);
        //选择大的子树返回
        return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        func(root);
        return res;
    }
};


