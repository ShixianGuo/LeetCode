/*根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

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

TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right, unordered_map<int, int> m){
    
    if(preorder_left > preorder_right)
        return nullptr;

    int preorder_root = preorder_left;
    int inorder_root = m[preorder[preorder_left]];

    TreeNode *root = new TreeNode(preorder[preorder_left]);
    int size_left_subtree = inorder_root - inorder_left;

    root->left = helper(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1, m);
    root->right = helper(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right, m);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> m;
    for(int i = 0; i < inorder.size(); i++){
        m[inorder[i]] = i;
    }        
    return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, m);
}