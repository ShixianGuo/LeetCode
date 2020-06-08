class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            set<char> s1;
            set<char> s2;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.'&&s1.find(board[i][j])!=s1.end())
                    return false;
                else if(board[i][j]!='.')
                    s1.insert(board[i][j]);
                if(board[j][i]=='.')continue;
                if(s2.find(board[j][i])!=s2.end())
                    return false;
                else
                    s2.insert(board[j][i]);
            }
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                set<char> s;
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        if(board[k][l]=='.')continue;
                        if(s.find(board[k][l])!=s.end())
                            return false;
                        else
                            s.insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
};