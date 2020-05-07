class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2)
            return s.size();
        int res = 0;
        int umap[128];
        for (auto &i : umap)
            i = -1;
        int first = 0;
        vector<int> dp(s.size());
        dp[0] = 1;
        umap[s[0]] = 0;

        for (int i = 1; i < s.size(); i++) {
            if (umap[s[i]] >= first) {
                dp[i] = i - umap[s[i]];
                first = umap[s[i]] + 1;
                umap[s[i]] = i;
            }
            else {
                dp[i] = dp[i - 1] + 1;
                umap[s[i]] = i;
            }
            if (res < dp[i])
                res = dp[i];
        }
        return res;
    }
};
