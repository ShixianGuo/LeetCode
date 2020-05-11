    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<vector<TreeNode*>> s;        
        vector<TreeNode*> a;
        a.push_back(root);
        s.push_back(a);
        int i = 1;
        while(a.size()!=0){
            i++;
            int flag = 0;
            vector<TreeNode*> b;
            for(int i=0;i<a.size();i++){
                if(a[i]!=NULL){
                    b.push_back(a[i]->left);
                    b.push_back(a[i]->right);
                }
            }
            s.push_back(b);
            a = b;
        }
        return s.size()-2;
    }
