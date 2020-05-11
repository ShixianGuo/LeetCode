class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            set<char> s;
            for(int j=0;j<9;++j){
                if(board[i][j]!='.')
                    if(s.find(board[i][j])!=s.end()) return false;
                    else s.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;++i){
            set<char> s;
            for(int j=0;j<9;++j){
                if(board[j][i]!='.')
                    if(s.find(board[j][i])!=s.end()) return false;
                    else s.insert(board[j][i]);
            }
        }
        for(int k=0;k<9;++k){
            set<char> s;
            for(int i=0;i<3;++i)
                for(int j=0;j<3;++j)
                    if(board[k/3*3+i][k%3*3+j]!='.')
                        if(s.find(board[k/3*3+i][k%3*3+j])!=s.end()) return false;
                        else s.insert(board[k/3*3+i][k%3*3+j]);
        }
            
        return true;
    }
};