class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans; 
        int start = -1, maxLen = -1;
        if(n <= 1) return s;
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for(int j = 0; j < n; j++) {
            for(int i = 0; i <= j; i++) {
                if(j-i < 3) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = dp[i+1][j-1] && s[i]==s[j]; 
                }
                if(dp[i][j] && j-i+1>maxLen) {
                    start = i;
                    maxLen = j-i+1;
                }
            }
        }
        ans = s.substr(start,maxLen);
        return ans;
    }
};