#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> levelOrderBottom(TreeNode* root){
    if(root == NULL)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> res;
    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i = 0; i < n; i++){
            TreeNode* temp = q.front();
            q.pop();
            if(!temp)
                continue;
            level.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }        
        res.push_back(level);
    }
    reverse(res.begin(), res.end());

    return res;
}
