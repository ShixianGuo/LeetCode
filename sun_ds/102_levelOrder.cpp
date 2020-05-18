// @File   : 102_levelOrder.cpp
// @Source : https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
// @Title  : 102. 二叉树的层次遍历
// @Auther : sun_ds
// @Date   : 2020/5/14

/**  题目描述：
    给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

    例如:
    给定二叉树: [3,9,20,null,null,15,7],

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
 * 层次遍历
 *
 * 1.递归
 *   dfs(root,level)
 *   添加level进去。将各个root->val放到对应层
 *      if(root->left != NULL)
 *         dfs(root->left, level + 1);
 *      if(root->right != NULL)
 *         dfs(root->right, level + 1);
 * 2.迭代
 *  使用队列queue
 *  2.1使用特殊标志标记当前层的结束。
 *     从queue中出队，并将该节点的左右节点入队。
 *     遇到特殊标记，一层结束，加入res
 *  2.2保存当前队列长度，这些为一层的节点。
 *     for循环这个保存的队列长度，将各个出队的节点的值加入res对应层，并将各节点左右孩子入队。
 *
 */

//dfs
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
    vector<vector<int>> res;
    void dfs(TreeNode* root, int level){
        if(res.size() < level){
            res.push_back({});
        }
        res[level - 1].push_back(root->val);
        if(root->left != NULL)
            dfs(root->left, level + 1);
        if(root->right != NULL)
            dfs(root->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        dfs(root,1);
        return res;
    }
};

//迭代(队列)
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
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(0);
        vector<vector<int>> res;
        vector<int> t;
        while(q.size() > 1){
            int flag = 0;
            TreeNode* temp = q.front();
            t.push_back(temp->val);
            q.pop();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);

            if(q.front() == 0){
                res.push_back(t);
                t.clear();
                q.pop();
                q.push(0);
            }
        }
        return res;
    }
};

//迭代(队列)
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
        if(root == NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> t;
            int num = q.size();
            for(int i=0;i<num;++i){
                TreeNode* temp = q.front();
                t.push_back(temp->val);
                q.pop();
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            res.push_back(t);
        }
        return res;
    }
};

