
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, 0);
        return res;
    }
    void backtrack(vector<vector<string>>& res, vector<string>& board, int row) {
        if(row == board.size()) {
            res.push_back(board);
            return;
        }
        for(int col = 0; col < board[0].size(); col++) {
            if(isVaild(board, row, col) == false) { continue; }
            board[row][col] = 'Q';
            backtrack(res, board, row + 1);
            board[row][col] = '.';
        }
    }
    bool isVaild(const vector<string>& board, int row, int col) {
        for(int i = 0; i < board.size(); i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        // right-up
        for(int i = row - 1, j = col + 1; i >= 0 && j < board[0].size(); i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        //left-up
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
