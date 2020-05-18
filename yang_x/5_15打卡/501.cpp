/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 
////申请额外空间
class Solution {
public:
    void findMode(TreeNode* root, map<int,int>& temp){
        if (root == NULL){
            return;
        }
        temp[root->val]++;
        if (root -> left != NULL)
            findMode(root -> left, temp);
        if (root -> right != NULL)
            findMode(root -> right, temp);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        map<int, int> temp;
        vector<int> ans;
        findMode(root, temp);
        int maxtime = 0;
        for (auto i : temp){
            if (i.second > maxtime){
                maxtime = i.second;
                ans.clear();
                ans.push_back(i.first);
            }
            else if (i.second == maxtime)
                ans.push_back(i.first);
        }
        return ans;
    }
};


////不申请额外空间
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    void findMode(TreeNode* root, int& curnum, int& maxnum, int& lastnum, vector<int>& ans){
        if (root -> left != NULL)
            findMode(root -> left, curnum, maxnum, lastnum, ans);
        if (root -> val == lastnum){
            curnum++;
            if (maxnum == curnum){
                ans.push_back(root -> val);
            }
            else if (maxnum < curnum){
                ans.clear();
                ans.push_back(root -> val);
                maxnum = curnum;
                lastnum = root -> val;
            }
        }
        else{
            if (maxnum == 1)
                ans.push_back(root -> val);
            curnum = 1;
            lastnum = root -> val;
        }
        if (root -> right != NULL)
            findMode(root -> right, curnum, maxnum, lastnum, ans);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<int> ans;
        int curnum = 0;     //当前元素出现次数
        int maxnum = 1;     //出现最多的元素的次数
        int lastnum = root->val;    //上一个节点的值
        findMode(root, curnum, maxnum, lastnum, ans);
        return ans;
    }
};