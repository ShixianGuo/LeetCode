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
    vector<int> findMode(TreeNode* root){
        vector<int> ans;
        inOrder(root, ans);
        unordered_map<int, int> m;
        for(auto val : ans)
            m[val] += 1;
        int max_num = 0;
        vector<int> output;
        for(auto ptr = m.begin(); ptr != m.end(); ptr++){
            if(ptr->second > max_num){
                max_num = ptr->second;
                output.clear();
            }
            if(ptr->second == max_num)
                output.push_back(ptr->first);
        }
        return output;
    }

    void inOrder(TreeNode *root, vector<int> &res){
        if(root == NULL)
            return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
    
};