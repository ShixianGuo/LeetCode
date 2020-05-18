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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int cur=1,next=0;
        vector<int> tmp;
        while(!q.empty()){
            TreeNode *t=q.front();
            q.pop();
            tmp.emplace_back(t->val);
            --cur;
            if(t->left) {q.push(t->left);++next;}
            if(t->right) {q.push(t->right);++next;}
            if(!cur) {ans.emplace_back(tmp);tmp.clear();cur=next;next=0;}
        }
        return ans;
    }
};