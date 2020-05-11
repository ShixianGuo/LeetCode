// @File   : 145_postorderTraversal.cpp
// @Source : https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
// @Title  : 145. 二叉树的后序遍历
// @Auther : sun_ds
// @Date   : 2020/5/1

/**  题目描述：
    给定一个二叉树，返回它的 后序 遍历。

    示例:

    输入: [1,null,2,3]
       1
        \
         2
        /
       3

    输出: [3,2,1]
    进阶: 递归算法很简单，你可以通过迭代算法完成吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 后序遍历
 * 1.递归
 *  顺序：左右根
 * 2.迭代
 *  使用栈
 *  入栈顺序 先左后右
 *  效果 根-右-左
 *  反序结果 即 左-右-根 后序遍历
 * 3.迭代
 *  一路入栈左孩子节点，知道叶子节点。
 *  判断是否有右孩子，以及右子树是否被遍历过，比较右孩子和last是否相等。
 *  如果没有右孩子或者右子树被遍历过，那么直接输出当前节点值。并更新last。
 *  否则，转向右孩子节点。
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
    vector<int> res;
public:
    void func(TreeNode* root){
        if(root==nullptr) return;
        func(root->left);
        func(root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        func(root);
        return res;
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        //根-右-左的反序  即 左-右-根
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            res.push_back(node->val);
            if(node->left!=nullptr) s.push(node->left);
            if(node->right!=nullptr) s.push(node->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* temp = root;
        TreeNode* last = nullptr;  //记录被遍历过的右子树
        while(!s.empty()||temp!=nullptr){
            //一直入栈左孩子
            while(temp!=nullptr){
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            if(temp->right==nullptr||temp->right==last){    //没有右孩子或者整个右子树都遍历过了
                res.push_back(temp->val);
                s.pop();
                last = temp;//遍历完了，更新last，使得更上一层节点可以知道整个右子树也遍历完了
                temp = nullptr;//temp置空，不再向下搜索。只执行temp = s.top();从栈中拿上面的节点
            }else{
                //转向右孩子
                temp = temp->right;
            }
        }
        return res;
    }
};