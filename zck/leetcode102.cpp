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
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res;
        while (que.size() != 0) {
            int size = que.size();
            vector<int> level;
            while (size --) {
                TreeNode* cur = que.front();
                que.pop();
                if (!cur) {
                    continue;
                }
                level.push_back(cur->val);
                que.push(cur->left);
                que.push(cur->right);
            }
            if (level.size() != 0) {
                res.push_back(level);
            }
        }
        return res;
    }
};