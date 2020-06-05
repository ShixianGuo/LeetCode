/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
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

TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right, unordered_map<int, int> m){
    if(postorder_left > postorder_right)
        return nullptr;

    int postorder_root = postorder_right;
    int inorder_root = m[postorder[postorder_right]];
    TreeNode *root = new TreeNode(inorder[inorder_root]);
    int left_tree_size = inorder_root - inorder_left;

    root->left = helper(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_left + left_tree_size -1 , m);
    root->right = helper(inorder, postorder, inorder_root  + 1, inorder_right, postorder_left + left_tree_size, postorder_right - 1, m);
    
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){    
    unordered_map<int, int> m;
    for(int i = 0; i < inorder.size(); i++){
        m[inorder[i]] = i;
    }
    return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, m);
}