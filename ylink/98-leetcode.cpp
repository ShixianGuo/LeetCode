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
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        else
        {
            //left max
            auto left_max = root->left;
            if(left_max)
            {
                while(left_max->right)
                    left_max = left_max->right;
            }
            //right min
            auto right_min = root->right;
            if(right_min)
            {
                while(right_min->left)
                    right_min = right_min->left;
            }
            //cmp, and recur cmp
            bool left_valid = true, right_valid = true;
            if(left_max)
            {
                left_valid = left_max->val < root->val;
            }
            if(right_min)
            {
                right_valid = root->val < right_min->val;
            }
            return left_valid && right_valid && isValidBST(root->left) && isValidBST(root->right);
        }
    }
    
};
