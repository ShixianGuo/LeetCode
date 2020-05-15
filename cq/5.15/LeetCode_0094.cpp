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
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        TreeNode *p=root;
        while(p||st.size()){
            while(p){
                st.push(p);
                p=p->left;
            }
            p=st.top();
            st.pop();
            ans.emplace_back(p->val);
            p=p->right;
        }
        return ans;
    }
};