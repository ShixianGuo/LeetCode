#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root){
    if(!root)
        return {};

    queue<Node*> q;
    q.push(root);

    vector<vector<int>> res;
    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i = 0; i < n; i++){
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->val);

            vector<Node*> children = temp->children;
            for(auto child : children){
                if(child == NULL)
                    continue;
                q.push(child);
            }
        }
        if(!level.empty()){
            res.push_back(level);
        }
    }
    return res;
}
