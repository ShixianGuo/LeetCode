class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> dp(256, -1);
        int max_len = 0;
        int front = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(dp[s[i]] >= front)
            {
                front = dp[s[i]] + 1; 
            }
            dp[s[i]] = i;
            max_len = max(max_len, i - front + 1);
        }
        return max_len;
    }
};
