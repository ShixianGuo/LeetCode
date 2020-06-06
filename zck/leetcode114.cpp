#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode* root){
    TreeNode *cur = root->left;

    while(cur->right != NULL){
        cur = cur->right;
    }
    cur->right = root->right;
    cur->right = cur->left;

    flatten(root->right);
}

void flatten(TreeNode* root){
    if(root ==  NULL)
        return;

    TreeNode *cur = root->left;
    if(root->left != NULL){
        while(cur->right != NULL){
            cur = cur->right;
        }
        cur->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    flatten(root->right);
}

