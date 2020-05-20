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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr){
            root = new TreeNode(val);
        }
        TreeNode* _root = root;
        bool flag = true;
        while (flag){
            if (_root -> val < val && _root -> right != nullptr){
                _root = _root -> right;
            }
            else if (_root -> val > val && _root -> left != nullptr){
                _root = _root -> left;
            }
            else{
                flag = false;
            }
        }
        if (_root -> val > val){
            TreeNode* insert_left = new TreeNode(val);
            _root -> left = insert_left;
        }
        else if (_root -> val < val){
            TreeNode* insert_right = new TreeNode(val);
            _root -> right = insert_right;
        }
        return root;
    }
};