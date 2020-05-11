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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p=root;
        while(p||st.size()){
            while(p){
                res.emplace_back(p->val);
                st.push(p->left);
                p=p->right;
            }
            p=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};