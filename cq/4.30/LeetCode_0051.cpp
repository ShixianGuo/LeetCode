class Solution
{

public:
    void dfs(vector<vector<string>> &res, vector<bool> &hasQueen, vector<int> &Queen, int n, vector<string> &tmp, int index)
    {
        if (index == n)
        {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (!hasQueen[i])
            {
                bool flag = 1;
                for (int pre = 0; pre < index; ++pre)
                {
                    if (abs(index - pre) == abs(i - Queen[pre]))
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    Queen[index] = i;
                    tmp[index][i] = 'Q';
                    hasQueen[i] = 1;
                    dfs(res, hasQueen, Queen, n, tmp, index + 1);
                    hasQueen[i] = 0;
                    tmp[index][i] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        string s;
        s.assign(n, '.');
        vector<string> tmp(n);
        fill(tmp.begin(), tmp.end(), s);
        vector<vector<string>> res;
        vector<bool> hasQueen(n);
        vector<int> Queen(n);
        fill(hasQueen.begin(), hasQueen.end(), 0);
        fill(Queen.begin(), Queen.end(), 0);
        dfs(res, hasQueen, Queen, n, tmp, 0);
        return res;
    }
};