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

int levelOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    int min_depth = 0;
    while(!q.empty()){
        min_depth++;
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL)
                continue;
            if(temp->left == NULL && temp->right == NULL)
                return min_depth;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return 0;
}

int minDepth(TreeNode *root){
    return levelOrder(root);
}
