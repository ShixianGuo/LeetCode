class Solution {
    bool dfs(string s,int l,int r){
        if(l==r) return s[l]=='t';
        if(s[l]=='!') return !dfs(s,l+2,r-1);
        bool ans=s[l]=='&';
        int pre=l+2,depth=1;
        for(int i=pre;depth;++i){
            if(s[i]=='(') ++depth;
            else if(s[i]==')') --depth;
            if(s[i]==','&&depth==1||!depth){
                if(s[l]=='&') ans&=dfs(s,pre,i-1);
                else if(s[l]=='|') ans|=dfs(s,pre,i-1);
                pre=i+1;
            }
        }
        return ans;
    }
public:
    bool parseBoolExpr(string expression) {
        return dfs(expression,0,expression.size()-1);
    }
};