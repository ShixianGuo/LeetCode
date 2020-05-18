

////////////递归

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
    void inorderTraversal(TreeNode* root, vector<int>& ans){
        if (root -> left != NULL)
            inorderTraversal(root -> left, ans);
        ans.push_back(root -> val);
        if (root -> right != NULL)
            inorderTraversal(root -> right, ans);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<int> ans;
        inorderTraversal(root, ans);
        return ans;
    }
};


//////迭代
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};
        stack<TreeNode*> temp;
        vector<int> ans;
        temp.push(root);
        int sta_len = temp.size();
        while(sta_len){
            TreeNode* tree_temp;
            tree_temp = temp.top();
            temp.pop();
            if (tree_temp -> left == NULL){
                ans.push_back(tree_temp -> val);
                if (tree_temp -> right != NULL){
                    temp.push(tree_temp -> right);
                }
            }
            else {
                TreeNode* tree_templ = tree_temp -> left;
                tree_temp -> left = NULL;
                temp.push(tree_temp);
                temp.push(tree_templ);
            }
            sta_len = temp.size();
        }
        return ans;
    }
};