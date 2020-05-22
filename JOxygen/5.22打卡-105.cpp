class Solution { 
public:
    TreeNode* preIn(vector<int>& pre, int prel, int prer,
                    vector<int>& in, int inl, int inr,
                    unordered_map<int, int> &M) {
        //[left, right)
        //hashmap start from 0
        if(prel >= prer || inl >= inr) return nullptr;
        TreeNode* root = new TreeNode(pre[prel]);
        int mid = M[pre[prel]];
        int offset = mid - inl;
        root->left = preIn(pre, prel+1, prel+1+offset, in, inl, mid, M);
        root->right = preIn(pre, prel+1+offset, prer, in, mid+1, inr, M);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> M;
        int idx = 0;
        for(auto it: inorder) {
            M[it] = idx++;
        }
        return preIn(preorder, 0, preorder.size(), inorder, 0, inorder.size(), M);
        
    }
};