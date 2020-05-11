class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int le=maxDepth(root->left);
        int ri=maxDepth(root->right);
        return 1+max(le,ri);
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* create(vector<int>& pre, vector<int>& in, int preL, int preR, int inL, int inR)
    {
        if (preL > preR)//当二叉树没有左右节点的时候，说明是叶子节点，即空子树时递归结束
            return NULL;

        TreeNode* root = new TreeNode;
        root->val = pre[preL];//将pre的preL值放入到结构体中，这里是确定二叉树的根，即先序遍历的第一个节点
        int i;
        for (i = inL; i <= inR; i++)//在中序序列中区分左子树和右子树 
        {
            if (in[i] == pre[preL])
                break;
        }
        int numLeft = i - inL;//看左边是否还有节点 
        //注意这里没有对numLeft的数目进行判断！！ 
        root->left = create(pre, in, preL + 1, preL + numLeft, inL, i - 1);
        root->right = create(pre, in, preL + numLeft + 1, preR, i + 1, inR);
        return root;
    }


};