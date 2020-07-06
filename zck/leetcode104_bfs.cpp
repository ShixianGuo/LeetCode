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
int maxDepth(TreeNode *root){
    int ans = 0;
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode *temp;
            temp = q.front();
            q.pop();
            if(!temp)
                continue;
            level.push_back(temp->val);
            q.push(temp->left);
            q.push(temp->right);
        }
        if(!level.empty())
            ans++;
    }
    return ans;
}
};