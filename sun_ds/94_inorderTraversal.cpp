// @File   : 94_inorderTraversal.cpp
// @Source : https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// @Title  : 94. 二叉树的中序遍历
// @Auther : sun_ds
// @Date   : 2020/5/15

/**  题目描述：
    给定一个二叉树，返回它的中序 遍历。

    示例:

    输入: [1,null,2,3]
       1
        \
         2
        /
       3

    输出: [1,3,2]
    进阶: 递归算法很简单，你可以通过迭代算法完成吗？



    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 中序遍历
 * 左-中-右
 *
 * 1.递归法
 *  左中右
 * 2.迭代法
 *  使用stack保存节点
 *  一路向左节点入栈，直到找到最左边的叶子节点。
 *  叶子节点的孩子即为空，将栈顶节点的值存储进res，栈顶节点出栈。临时节点指向其右孩子继续迭代。
 *
 */

//递归
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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        recursion(root);
        return res;
    }
    void recursion(TreeNode* root){
        if(root == NULL) return;
        recursion(root->left);
        res.push_back(root->val);
        recursion(root->right);
    }
};


//迭代
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> q;
        TreeNode* temp = root;
        vector<int> res;
        while(!q.empty()||temp!=NULL){
            if(temp!= NULL){
                q.push(temp);
                temp = temp->left;
            }else{
                temp = q.top();
                q.pop();
                res.push_back(temp->val);
                temp = temp->right;
            }
        }
        return res;
    }
};

