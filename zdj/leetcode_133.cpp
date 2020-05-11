class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    unordered_map<int, Node*> record;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;

        Node* my_root = new Node(node->val);
        record[node->val] = my_root;
        deep_copy(my_root, node);
        return my_root;
    }

    void deep_copy(Node* my_root, Node* origin_root) {
        for(auto p = origin_root->neighbors.begin(); p != origin_root->neighbors.end(); p++) {
            if(record.find((*p)->val) == record.end()) {
                Node* tmp = new Node((*p)->val);
                my_root->neighbors.push_back(tmp);
                record[(*p)->val] = tmp;
                deep_copy(tmp, *p);
            }
            else {
                my_root->neighbors.push_back(record[(*p)->val]);
            }
        }
    }
};