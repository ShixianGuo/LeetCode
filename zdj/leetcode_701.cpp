using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recur(TreeNode* root, const int& target) {
        if(target < root->val) {
            if(root->left)
                recur(root->left, target);
            else
                root->left = new TreeNode(target);
        }
        else {
            if(root->right)
                recur(root->right, target);
            else
                root->right = new TreeNode(target);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        recur(root, val);
        return root;
    }
};