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
    bool isTrue(TreeNode* &root,int &val,bool &flag){
        if(!root) return 1;
        if(!isTrue(root->left,val,flag)){
            return 0;
        }
        
        if(!flag) {flag=1;val=root->val;}
        else if(val>=root->val) return 0;
        val=root->val;
        
        return isTrue(root->right,val,flag);
    }
public:
    bool isValidBST(TreeNode* root) {
        bool flag=0;  //最左边节点赋给val的标志
        int val=INT_MIN;
        return isTrue(root,val,flag);
    }
};