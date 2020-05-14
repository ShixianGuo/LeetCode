/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Solution() : curtimes(0), maxtimes(0), curval(INT_MIN) {}
    
    vector<int> findMode(TreeNode* root) 
    {
        inorder_traversal(root);
        return res;
    }
    
    void inorder_traversal(TreeNode* root)
    {
        if(root)
        {
            inorder_traversal(root->left);
            
            curtimes++;
            if(root->val != curval)
            {
                curval = root->val;
                curtimes = 1;
            }
            if(curtimes > maxtimes)
            {
                maxtimes = curtimes;
                res.resize(1);
                res[0] = curval;
            }
            else if(curtimes == maxtimes)
            {
                res.push_back(curval);
            }
            inorder_traversal(root->right);
        }
    }
private:
    vector<int> res;
    int curval, maxtimes, curtimes;
};
