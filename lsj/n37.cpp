class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);    
    }
    bool backtrack(vector<vector<char>> &board, int row, int col) {
        if(col == 9) return backtrack(board, row + 1, 0);

        if(row == 9) return true;

        for(int i = row; i < 9; i++) {
            for(int j = col; j < 9; j++) {
                if(board[i][j] != '.') {
                    return backtrack(board, i, j + 1);
                }

                for(char ch = '1'; ch <= '9'; ch++) {
                    if(!isVaild(board, i, j, ch)) continue;

                    board[i][j] = ch;
                    if(backtrack(board, i, j + 1)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return false;
    }
    bool isVaild(vector<vector<char>> board, int row, int col, char n) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == n) return false;
            if(board[i][col] == n) return false;
            if(board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == n) return false;
        }
        return true;
    }
};
