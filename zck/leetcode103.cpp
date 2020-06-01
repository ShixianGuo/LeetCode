#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    
    //注意，for循环中不要使用q.size(),在push之后q.size()会变化
    int l = 0;
    while(!q.empty()){
        vector<int> level;
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode *temp = q.front();
            q.pop();
            if(!temp)
                continue;
            level.push_back(temp->val);
            q.push(temp->left);
            q.push(temp->right);
        }
        if(!level.empty()){
            if(l % 2 == 0){
                res.push_back(level);
            }
            else{
                reverse(level.begin(), level.end());
                res.push_back(level);
            }
        }
        l++;
    }
    return res;
}

};