/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) 
    {
        if(preorder.empty())
            return nullptr;
        auto node = new TreeNode(-1);
        auto it2root_preorder = preorder.begin();
        auto it2root_inorder = find(inorder.begin(), inorder.end(), *it2root_preorder);
        
        auto inorder_left_tree_begin = inorder.begin();
        auto inorder_left_tree_end = it2root_inorder;
        auto inorder_right_tree_begin = it2root_inorder + 1;
        auto inorder_right_tree_end = inorder.end();
        
        auto preorder_left_tree_begin = preorder.begin() + 1;
        auto preorder_left_tree_end = preorder_left_tree_begin + (inorder_left_tree_end - inorder_left_tree_begin);
        auto preorder_right_tree_begin = preorder_left_tree_end;
        auto preorder_right_tree_end = preorder.end();
        
        node->val = *it2root_preorder;
        if(preorder_left_tree_end - preorder_left_tree_begin == 0)
        {
            node->left = nullptr;
        }
        else
        {
            node->left = buildTree(vector<int>(preorder_left_tree_begin, preorder_left_tree_end), vector<int>(inorder_left_tree_begin, inorder_left_tree_end));
        }
        if(preorder_right_tree_end - preorder_right_tree_begin == 0)
        {
            node->right = nullptr;
        }
        else
        {
            node->right = buildTree(vector<int>(preorder_right_tree_begin, preorder_right_tree_end), vector<int>(inorder_right_tree_begin, inorder_right_tree_end));
        }
        return node;
    }
};
