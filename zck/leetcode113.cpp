/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &res){
    if(!root)
        return;

    if(root->val == sum && !root->left && !root->right){
        path.push_back(root->val);
        res.push_back(path);
        path.pop_back();
        return;
    }
      
    path.push_back(root->val);

    if(root->left){
        dfs(root->left, sum - root->val, path, res);
    }
    if(root->right){
        dfs(root->right, sum - root->val, path, res);
    }

    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    
    dfs(root, sum, path, res);
    return res;
}


