#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root, vector<int> &res){
    if(root == NULL)
        return;
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preOrder(root, res);

    return res;
}