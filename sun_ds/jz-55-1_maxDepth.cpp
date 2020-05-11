// @File   : jz-55-1_maxDepth.cpp
// @Source : https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
// @Title  : 面试题55 - I. 二叉树的深度
// @Auther : sun_ds
// @Date   : 2020/5/2

/**  题目描述：
    输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

    例如：

    给定二叉树 [3,9,20,null,null,15,7]，

        3
       / \
      9  20
        /  \
       15   7
    返回它的最大深度 3 。

     

    提示：

    节点总数 <= 10000
    注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.递归
 *  返回当前节点的最大深度 = max(左子树最大深度,右子树最大深度)+1;
 *  边界条件，root==nullptr，返回深度0.
 *
 * 2.迭代
 *  使用queue，构建层序遍历。
 *  使用depth统计二叉树深度。
 *
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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

//迭代 层序遍历
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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int depth=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            depth++;
            int len = q.size();
            for(int i=0;i<len;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return depth;
    }
};

