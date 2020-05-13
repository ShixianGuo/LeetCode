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
    TreeNode* dfs(string &s,int depth){
        if(s.empty()) return nullptr;
        int i=0,j=depth;
        while(j--){
            if(s[i]=='-')
                ++i; 
            else return nullptr;
        }
        int len=1;
        j=i+1;
        while(s[j]>='0'&&s[j]<='9') {++len;++j;}

        TreeNode *root;
        if(len>1) root=new TreeNode(stoi(s.substr(i,len)));
        else root=new TreeNode(s[i]-'0');
        s.erase(0,i+len);
        root->left=dfs(s,depth+1);
        root->right=dfs(s,depth+1);
        return root;
    }
public:
    TreeNode* recoverFromPreorder(string S) {
        return dfs(S,0);
    }
};