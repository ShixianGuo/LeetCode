class Solution
{
    void dfs(vector<string> &res, vector<bool> &vis, string s, string &tmp, int index)
    {
        if (index == s.size())
        { 
            res.emplace_back(tmp);
            return;
        }
        for (int i = 0; i < s.size(); ++i){
            if(i&&vis[i-1]&&s[i-1]==s[i]) continue;
            if (!vis[i])
            {
                tmp.push_back(s[i]);
                vis[i] = 1;
                dfs(res, vis, s, tmp, index + 1);
                vis[i] = 0;
                tmp.pop_back();
            }
        } 
    }

public:
    vector<string> permutation(string s)
    {
        vector<string> res;
        if (s.empty())
            return res;
        sort(s.begin(), s.end());
        string tmp;
        vector<bool> vis(s.size(), 0);
        dfs(res, vis, s, tmp, 0);
        return res;
    }
};