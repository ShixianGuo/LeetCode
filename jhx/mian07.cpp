/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
 

限制：

0 <= 节点个数 <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* build(int pre_l, int pre_r, int in_l, int in_r,
                    vector<int>& preorder, vector<int>& inorder) {
        if (pre_l >= pre_r) {
            return nullptr;
        }
        int root = preorder[pre_l];
        if (pre_l == (pre_r - 1)) {
            TreeNode* t = new TreeNode(preorder[pre_l]);
            t->left = t->right = nullptr;
            return t;
        }
        TreeNode* t = new TreeNode(root);
        int zroot = root;
        for (int i = in_l; i < in_r; i++) {
            if (zroot == inorder[i]) {
                zroot = i;
                break;
            }
        }

        t->left = build(pre_l + 1, pre_l+ (zroot - in_l) + 1, in_l, zroot,preorder,inorder);
        t->right = build(pre_l + (zroot - in_l) + 1, pre_r, zroot + 1, in_r,preorder,inorder);

        return t;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, preorder.size(), 0, inorder.size(), preorder, inorder);
    }
};

int main() {}