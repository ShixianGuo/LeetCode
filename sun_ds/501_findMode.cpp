// @File   : 501_findMode.cpp
// @Source : https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
// @Title  : 501. 二叉搜索树中的众数
// @Auther : sun_ds
// @Date   : 2020/5/15

/**  题目描述：
    给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

    假定 BST 有如下定义：

    结点左子树中所含结点的值小于等于当前结点的值
    结点右子树中所含结点的值大于等于当前结点的值
    左子树和右子树都是二叉搜索树
    例如：
    给定 BST [1,null,2,2],

       1
        \
         2
        /
       2
    返回[2].

    提示：如果众数超过1个，不需考虑输出顺序

    进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 对于递增数组，取出现频率最高的数。
 * 遍历数组，判断，若当前值与前面值相等，计数加1;若不相等计数变为1,重新开始。
 * 同时判断计数值和最大值的关系。
 * 计数值 等于 最大值 将当前值放入 res
 * 计数值 大于 最大值 res 清零，并将当前值放入 res
 *
 * 中序遍历可以获得递增数组。
 *
 * 在递归过程中当做遍历数组的过程。关键在于使用 pre 保存前一个前继节点。
 *
 * 需要有前处理，即第一个节点的 pre ,此处定义为 nullptr 作为标记。
 *
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
    int max_count = 0;
    vector<int> res;
    int cur_count = 1;
    TreeNode* pre = nullptr;
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        if(pre) cur_count = (pre->val == root->val) ? cur_count + 1 : 1;
        //下面和 max_count 的比较，可以考虑在pre->val 和 root->val 不相等的时候再执行。
        //但要注意后处理
        if(cur_count == max_count){
            res.push_back(root->val);
        }else if(cur_count > max_count){
            //存在重复clear 与 push_back   cur_count 每次比 max_count 大 1
            res.clear();
            res.push_back(root->val);
            max_count = cur_count;
        }
        pre = root;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(root==nullptr) return {};
        int cur_count = 1;
        inorder(root);
        return res;
    }
};

