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
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        vector<int> path(10,0);
        path[root->val] = 1;
        dfs(root, path, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, vector<int> &path, int &ans) {
        if(root->left== NULL && root->right==NULL) {
            ans = isPali(path)?ans+1 : ans;
            return;
        }
        if(root->left) {
            path[(root->left)->val]++;
            dfs(root->left, path, ans);
            path[(root->left)->val]--;
        }
        if(root->right) {
            path[(root->right)->val]++;
            dfs(root->right, path, ans);
            path[(root->right)->val]--;
        }
    }
    
    bool isPali(vector<int> v) {
        int cnt = 0;
        for(int i = 1; i<=9; i++) {
            if(v[i] % 2 == 1) {
                ++cnt;
                if(cnt > 1) return false;
            }
        }
        return true;
    }
};