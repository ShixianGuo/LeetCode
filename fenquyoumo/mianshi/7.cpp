/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *bt(vector<int>& preorder, int st1,int ed1,vector<int>& inorder,int st2,int ed2)
    {
        if(st1>ed1)return NULL;
        TreeNode *root = new TreeNode(preorder[st1]);
        //cout<<preorder[st1]<<" "<<st1<<" "<<ed1<<" "<<st2<<" "<<ed2<<endl;
        if(ed1==st1)return root;
        //cout<<"do for"<<endl;
        for(int i=st2;i<=ed2;i++)
        {
            if(inorder[i]==preorder[st1])
            {
                root->left=bt(preorder,st1+1,i-st2+st1,inorder,st2,i-1);
                root->right=bt(preorder,i-st2+st1+1,ed1,inorder,i+1,ed2);
                return root;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bt(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};