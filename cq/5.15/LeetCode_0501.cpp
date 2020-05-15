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
    void dfs(TreeNode* &cur,TreeNode* &pre,vector<int> &res,int &curCnt,int &maxCnt){
        if(!cur) return;
        dfs(cur->left,pre,res,curCnt,maxCnt);

        //相关处理逻辑
        if(pre){
            if(pre->val==cur->val) ++curCnt;
            else curCnt=1;
        }
        if(curCnt==maxCnt) res.push_back(cur->val);
        else if(curCnt>maxCnt){
            res.clear();
            res.push_back(cur->val);
            maxCnt=curCnt;
        }
        pre=cur;

        dfs(cur->right,pre,res,curCnt,maxCnt);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode *cur=root,*pre=nullptr;
        int maxCnt=0,curCnt=1;
        dfs(cur,pre,res,curCnt,maxCnt);
        return res;
    }
};