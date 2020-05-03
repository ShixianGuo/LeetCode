/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
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
    TreeNode* reBuild(vector<int>& preorder, int preL, int preR, 
                    vector<int>& inorder, int inL, int inR){
        //第一行很关键
        if(preL>preR) return nullptr;
        TreeNode* root=new TreeNode(preorder[preL]);
        if(preL==preR) return root;
        //找到中序遍历中的根节点
        int index=inL;
        for(;index<=inR;++index){
            if(inorder[index]==root->val) break;
        }
        //左子树元素个数
        int k=index-inL;
        root->left=reBuild(preorder, preL+1, preL+k, inorder, inL,index-1);
        root->right=reBuild(preorder, preL+k+1, preR, inorder, index+1,inR);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) 
            return nullptr;
        return reBuild(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};