class Solution
{
    vector<string> ans;
    void dfs(string s, string ip, int n)
    {
        if (n > 3)
        {
            if (s.empty())
                ans.emplace_back(ip);
            return;
        }
        for (int i = 1; i < 4; ++i)
        {
            if (i > s.size())
                break;
            int val = stoi(s.substr(0, i));
            if (val > 255 || i != to_string(val).size())
                continue;
            dfs(s.substr(i), ip + s.substr(0, i) + (n == 3 ? "" : "."), n + 1);
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        string ip;
        ans.clear();
        dfs(s, ip, 0);
        return ans;
    }
};