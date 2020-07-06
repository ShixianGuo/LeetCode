#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int maxHeight(TreeNode *root){
    if(!root)
        return 0;
    return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}

bool isBalanced(TreeNode *root){
    if(!root)
        return true;
    return abs(maxHeight(root->left) - maxHeight(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);

}

