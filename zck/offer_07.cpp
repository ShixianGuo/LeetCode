/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(vector<int>& preorder, int preorder_left, int preorder_right, vector<int>& inorder, int inorder_left, int inorder_right, unordered_map<int, int>& m){
    if(preorder_left > preorder_right)
        return NULL;
    int root_val = preorder[preorder_left];
    TreeNode* root = new TreeNode(root_val);
    int index = m[root_val];
    int left_size = index - inorder_left;
    int right_size = inorder_right - index;

    root->left = helper(preorder, preorder_left + 1, preorder_left + left_size, inorder, inorder_left, index - 1, m);
    root->right = helper(preorder, preorder_left + left_size + 1, preorder_right, inorder, index + 1, inorder_right, m);
    
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    unordered_map<int, int> m;
    for(int i = 0; i < inorder.size(); i++){
        m[inorder[i]] = i;
    }
    return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size(), m);
}


