class Solution {
    int m=9,n=9;
    int backtrack(vector<vector<char>>& board,int i,int j){
        if(j==n) return backtrack(board,i+1,0);
        if(i==m) return true;
        if(board[i][j]!='.') return backtrack(board,i,j+1);

        for(char ch='1';ch<='9';++ch){
            if(!isValid(board,i,j,ch)) continue;
            board[i][j]=ch;
            if(backtrack(board,i,j+1)) return true;
            board[i][j]='.';
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board,int row,int col,char ch){
        for(int k=0;k<m;++k){
            if(board[row][k]==ch) return 0;
            if(board[k][col]==ch) return 0;
            if(board[row/3*3+k/3][col/3*3+k%3]==ch) return 0;
        }
        return 1;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board,0,0);
    }
};