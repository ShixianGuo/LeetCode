// @File   : 701_insertIntoBST.cpp
// @Source : https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/
// @Title  : 701. 二叉搜索树中的插入操作
// @Auther : sun_ds
// @Date   : 2020/5/20

/**  题目描述：
    给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。

    注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

    例如, 

    给定二叉搜索树:

            4
           / \
          2   7
         / \
        1   3

    和 插入的值: 5
    你可以返回这个二叉搜索树:

             4
           /   \
          2     7
         / \   /
        1   3 5
    或者这个树也是有效的:

             5
           /   \
          2     7
         / \
        1   3
             \
              4

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 比较当前节点值和插入的目标值。
 * 一直搜索到最接近目标值的地方。即到达了 nullptr。
 * 在此处新建一个节点接上去。
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        TreeNode* node = root;
        while(1){
            if(node->val > val){
                if(node->left == nullptr){
                    node->left = new TreeNode(val);
                    break;
                }
                node = node->left;
            }else{
                if(node->right == nullptr){
                    node->right = new TreeNode(val);
                    break;
                }
                node = node->right;
            }
        }
        return root;
    }
};

