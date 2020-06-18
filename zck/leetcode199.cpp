#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i = 0; i < n; i++){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL)
                continue;
            level.push_back(temp->val);
            q.push(temp->left);
            q.push(temp->right);
        }
        if(!level.empty())
            res.push_back(level.back());
    }   
    return res;
}

