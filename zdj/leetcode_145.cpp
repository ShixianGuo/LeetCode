#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode*, bool>> traver;
        traver.push(make_pair(root, false));
        while(!traver.empty()) {
            auto cur = traver.top();
            if(cur.first == nullptr) {
                traver.pop();
                continue;
            }
            if(cur.second) {
                result.push_back(cur.first->val);
                traver.pop();
            }
            else {
                traver.top().second = true;
                if(cur.first->right)
                    traver.push(make_pair(cur.first->right, false));
                if(cur.first->left)
                    traver.push(make_pair(cur.first->left, false));
            }
        }
        return result;
    }
};


