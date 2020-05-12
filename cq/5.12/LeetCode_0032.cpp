class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<2) return 0;
        int ans=0;
        vector<int> dp(s.size());
        for(int i=1;i<s.size();++i){
            if(s[i]==')'){
                if(s[i-1]=='(') dp[i]=(i-2>=0?dp[i-2]:0)+2;
                else if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
                    dp[i]=(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0)+dp[i-1]+2;
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};