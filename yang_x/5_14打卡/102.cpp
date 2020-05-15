/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//双队列方法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        queue<TreeNode*> p, q;
        vector<vector<int> > ans;
        p.push(root);
        while (!p.empty()|| !q.empty()){
            vector<int> temp;
            while(!p.empty()){
                TreeNode* ptemp = p.front();
                p.pop();
                temp.push_back(ptemp -> val);
                if (ptemp -> left != NULL)
                    q.push(ptemp -> left);
                if (ptemp -> right != NULL)
                    q.push(ptemp -> right);
            }
            if (temp.size() != 0)
                ans.push_back(temp);
            temp.clear();
            while(!q.empty()){
                TreeNode* qtemp = q.front();
                q.pop();
                temp.push_back(qtemp -> val);
                if (qtemp -> left != NULL)
                    p.push(qtemp -> left);
                if (qtemp -> right != NULL)
                    p.push(qtemp -> right);
            }
            if (temp.size() != 0)
                ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};


///单队列方法
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        queue<TreeNode*> p;
        vector<vector<int> > ans;
        p.push(root);
        int psize1 = p.size();
        while (psize1 != 0){
            vector<int> temp;
            while(psize1--){
                TreeNode* ptemp = p.front();
                p.pop();
                temp.push_back(ptemp -> val);
                if (ptemp -> left != NULL)
                    p.push(ptemp -> left);
                if (ptemp -> right != NULL)
                    p.push(ptemp -> right);
            }
            psize1 = p.size();
            if (temp.size() != 0)
                ans.push_back(temp);
        }
        return ans;
    }
};