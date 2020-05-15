/*
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
        vector<int> res;
        stack<pair<TreeNode*, int>> s;//也可以使用bool
        while(root!=nullptr||!s.empty()){
            if(root!=nullptr){
                s.push({root,0});
                root=root->left;
            }
            else{
                auto p=s.top();
                s.pop();
                //如果之前已经访问过两次了
                if(p.second==1){
                    res.push_back(p.first->val);
                }
                else{
                    //第二次访问
                    p.second=1;
                    s.push(p);
                    root=p.first->right;
                }
            }
        }
        return res;
    }
};