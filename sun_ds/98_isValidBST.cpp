// @File   : 98_isValidBST.cpp
// @Source : https://leetcode-cn.com/problems/validate-binary-search-tree/
// @Title  : 98. 验证二叉搜索树
// @Auther : sun_ds
// @Date   : 2020/5/7

/**  题目描述：
    给定一个二叉树，判断其是否是一个有效的二叉搜索树。

    假设一个二叉搜索树具有如下特征：

    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。
    示例 1:

    输入:
        2
       / \
      1   3
    输出: true
    示例 2:

    输入:
        5
       / \
      1   4
         / \
        3   6
    输出: false
    解释: 输入为: [5,1,4,null,null,3,6]。
         根节点的值为 5 ，但是其右子节点值为 4 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/validate-binary-search-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 判断其是否是一个有效的二叉搜索树
 *
 * 二叉搜索树，不仅需要满足左孩子小于右孩子大于父节点，而是左子树都小于右子树都大于父节点
 *
 * 1.中序遍历
 *  中序遍历的结果升序排列，则该二叉树必定是二叉搜索树
 *
 * 2.递归
 *  使用val记录前面的最大值
 *  判断当前根节点root->val和val之间的关系，若root->val <= val 那么不符合二叉搜索树性质。
 *
 *
 * 3.递归+区间
 *  递归时输入可取值的左右区间范围。不在该区间内，return false;
 *  递归左节点,右节点。并更新区间边界。
 *
 */


//中序遍历
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
    vector<int> temp;
    void func(TreeNode* root){
        if(root == NULL) return;
        func(root->left);
        temp.push_back(root->val);
        func(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        func(root);
        for(int i=1;i<temp.size();++i){
            if(temp[i-1] >= temp[i])
                return false;
        }
        return true;
    }
};
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
    bool inorder(TreeNode* root,long& val){
        if(root==nullptr) return true;
        if(!inorder(root->left,val)) return false;
        if(root->val <= val) return false;
        val = root->val;
        if(!inorder(root->right,val)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        //使用long做标志，不影响真正的二叉搜索树的值。
        long val = (long)INT_MIN - 1;
        return inorder(root,val);
    }
};

//递归+区间
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
    bool func(TreeNode* root,long s,long e){
        if(root->val <= s || root->val >= e)
            return false;
        if(root->left != NULL)
            if(!func(root->left,s,root->val))
                return false;
        if(root->right != NULL)
            if(!func(root->right,root->val,e))
                return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return func(root,LONG_MIN,LONG_MAX);
    }
};
class Solution {
public:
    bool func(TreeNode* root,long s,long e){
        if(root == NULL) return true;
        if(root->val <= s || root->val >= e) return false;
        if(!func(root->left,s,root->val)) return false;
        if(!func(root->right,root->val,e)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return func(root,LONG_MIN,LONG_MAX);
    }
};