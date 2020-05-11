#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> pre;
    vector<int> in;
public:
    TreeNode* recur(int pre_left, int pre_right, int in_left, int in_right) {
        if(pre_left > pre_right)
            return nullptr;
        TreeNode* root = new TreeNode(pre[pre_left]);
        int root_pos = find(in.begin(), in.end(), pre[pre_left]) - in.begin();
        int left_len = root_pos - in_left;
        root->left = recur(pre_left+1, pre_left + left_len, in_left, root_pos-1);
        root->right = recur(pre_left + left_len+1, pre_right, root_pos+1, in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        return recur(0, preorder.size()-1, 0, inorder.size()-1);
    }
};

