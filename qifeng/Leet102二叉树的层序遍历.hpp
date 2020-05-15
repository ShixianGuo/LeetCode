/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res; 
        if(root==nullptr) return res;
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root, 1));
        vector<int> curr;
        while(!Q.empty())
        {
            TreeNode* node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            //当上一个vector完成后才会开始下一个
            if(depth>res.size()+1)
            {
                //保存、清空、换一行
                res.push_back(curr);
                curr.clear();
            }
            curr.push_back(node->val);
            //新节点
            if(node->left) Q.push(make_pair(node->left, depth+1));
            if(node->right) Q.push(make_pair(node->right, depth+1));
        }
        res.push_back(curr);
        return res;
    }
};