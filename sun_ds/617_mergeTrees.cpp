// @File   : 617_mergeTrees.cpp
// @Source : https://leetcode-cn.com/problems/merge-two-binary-trees/
// @Title  : 617. 合并二叉树
// @Auther : sun_ds
// @Date   : 2020/5/14

/**  题目描述：
    给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

    你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

    示例 1:

    输入:
        Tree 1                     Tree 2
              1                         2
             / \                       / \
            3   2                     1   3
           /                           \   \
          5                             4   7
    输出:
    合并后的树:
             3
            / \
           4   5
          / \   \
         5   4   7
    注意: 合并必须从两个树的根节点开始。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/merge-two-binary-trees
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.递归+新建节点
 *  根据 t1 和 t2 的情况分类进行创建节点。递归的执行。
 * 2.递归自身
 *  若 t1=nullptr 返回 t2.若 t2=nullptr 返回 t1.
 *  否则，下降规模，递归。
 * 3.迭代 bfs
 * 4.迭代 dfs
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
    TreeNode* func(TreeNode* t1,TreeNode* t2){
        TreeNode* root = nullptr;
        if(t1!=nullptr&&t2==nullptr){
            root = new TreeNode(t1->val);
            root->left = func(t1->left,nullptr);
            root->right = func(t1->right,nullptr);
        }else if(t1==nullptr&&t2!=nullptr){
            root = new TreeNode(t2->val);
            root->left = func(nullptr,t2->left);
            root->right = func(nullptr,t2->right);
        }else if(t1!=nullptr&&t2!=nullptr){
            root = new TreeNode(t1->val+t2->val);
            root->left = func(t1->left,t2->left);
            root->right = func(t1->right,t2->right);
        }
        return root;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return func(t1,t2);
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr) return t2;
        if(t2 == nullptr) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;
    }
};

//bfs
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr) return t2;
        if(t2 == nullptr) return t1;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push(make_pair(t1,t2));
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* temp1 = temp.first;
            TreeNode* temp2 = temp.second;
            temp1->val += temp2->val;
            if(temp2->left!=nullptr){
                if(temp1->left==nullptr){
                    temp1->left = temp2->left;
                }else{
                    q.push(make_pair(temp1->left,temp2->left));
                }
            }
            if(temp2->right!=nullptr){
                if(temp1->right==nullptr){
                    temp1->right = temp2->right;
                }else{
                    q.push(make_pair(temp1->right,temp2->right));
                }
            }
        }
        return t1;
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr) return t2;
        if(t2 == nullptr) return t1;
        stack<pair<TreeNode*,TreeNode*>> s;
        s.push(make_pair(t1,t2));
        while(!s.empty()){
            auto temp = s.top();
            s.pop();

            TreeNode* temp1 = temp.first;
            TreeNode* temp2 = temp.second;

            if(temp1==nullptr||temp2==nullptr) continue;

            temp1->val += temp2->val;

            if(temp1->left==nullptr){
                temp1->left = temp2->left;
            }else{
                s.push(make_pair(temp1->left,temp2->left));
            }

            if(temp1->right==nullptr){
                temp1->right = temp2->right;
            }else{
                s.push(make_pair(temp1->right,temp2->right));
            }

        }
        return t1;
    }
};

