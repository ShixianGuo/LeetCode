

/*
LeetCode145
后序遍历
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<pair<TreeNode*, int>> s;//也可以使用bool
		while (root != nullptr || !s.empty()) {
			if (root != nullptr) {
				s.push({ root,0 });
				root = root->left;
			}
			else {
				auto p = s.top();
				s.pop();
				//如果之前已经访问过两次了
				if (p.second == 1) {
					res.push_back(p.first->val);
				}
				else {
					//第二次访问
					p.second = 1;
					s.push(p);
					root = p.first->right;
				}
			}
		}
		return res;
	}
};