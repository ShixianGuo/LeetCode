// @File   : jz-7_buildTree.cpp
// @Source : https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
// @Title  : 面试题07. 重建二叉树
// @Auther : sun_ds
// @Date   : 2020/5/2

/**  题目描述：
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

     

    注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 前序遍历：根 - 左 - 右
 * 中序遍历：左 - 根 - 右
 *
 * 因此，前序遍历的第一个值即为根节点。
 * 在中序遍历中找到与前序遍历中第一个值对应的位置。
 * 该位置的左面为当前根的整个左子树的元素，该位置的右面是当前根的整个右子树元素。
 * 中序遍历遍历以根为界限，拆分成两部分。 前序遍历根据中序遍历的左右子树元素个数，按照顺序也分成两部分，变成两个前序遍历。
 * 其中拆分后的每个前序遍历的第一个值仍为对应中序遍历的子树的根。
 *
 * 使用递归。
 * 依次执行。
 * 最终得到整个子树。
 *
 *
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
    TreeNode* func(vector<int>& preorder, vector<int>& inorder, int index, int left, int right){

        //index为preorder的索引
        //left和right为inorder的索引
        //temp也为inorder的索引，由inorder[temp] == preorder[index];

        if(left > right) return NULL;  //left == right 可以执行，只剩最后一个元素，他是叶子节点，左右子树都为null。
        TreeNode* root = new TreeNode(preorder[index]); //前序遍历的第一个值为根节点。
        int temp = left;
        while(inorder[temp] != preorder[index]) temp++; //在中序遍历中找到与根节点对应的坐标。前面为左子树，后面为右子树。
        // 拆分后的前序遍历的第一个位置分别为 index+1  和 index+1+左子树长度
        // temp对应中序中根节点对应的位置。
        // 中序左子树范围为 left，temp-1
        // 中序右子树范围为 temp+1 right
        root->left = func(preorder,inorder,index+1,left,temp-1);
        root->right = func(preorder,inorder,index+temp-left+1,temp+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return func(preorder,inorder,0,0,preorder.size()-1);
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
    TreeNode* func(vector<int>& preorder, vector<int>& inorder,int i1,int j1,int i2,int j2){

        //i1,j1为preorder当前考虑范围
        //i2,j2为inorder当前考虑范围
        //index为inorder中索引，有inorder[index]==preorder[i1];

        if(i1>j1||i2>j2) return nullptr;

        TreeNode* root = new TreeNode(preorder[i1]);
        int index = i2;
        while(inorder[index]!=preorder[i1]) index++;
        //index是inorder的坐标，给preorder用的话需要转换
        root->left = func(preorder,inorder,i1+1,i1+(index-i2),i2,index-1);
        root->right = func(preorder,inorder,i1+(index-i2)+1,j1,index+1,j2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return func(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};