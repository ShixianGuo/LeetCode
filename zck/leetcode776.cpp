#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> splitBST(TreeNode* root, int V){
    if(root == NULL){
        vector<TreeNode*> res(2);
        return res;
    }
    if(root->val <= V){
        vector<TreeNode*> res = splitBST(root->right, V);
        root->right = res[0];
        res[0] = root;
        return res;
    }
    else
    {
        vector<TreeNode*> res = splitBST(root->left, V);
        root->left = res[1];
        res[1] = root;
        return res;
    }
}
