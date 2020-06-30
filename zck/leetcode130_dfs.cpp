/* 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
*/

#include <iostream>
#include <vector>

using namespace std;
void dfs(vector<vector<char>>& board, int i, int j){
    int m = board.size();
    int n = board[0].size();

    board[i][j] = '#';

    if(i + 1 < m && board[i+1][j] == 'O'){
        dfs(board, i + 1, j);
    }
    
    if(i - 1 >= 0 && board[i-1][j] == 'O')
        dfs(board, i - 1, j);

    if(j + 1 < n && board[i][j+1] == 'O')
        dfs(board, i, j + 1);
    if(j - 1 >= 0 && board[i][j-1] == 'O')
        dfs(board, i, j - 1);
}

void solve(vector<vector<char>>& board){
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O')
                dfs(board, i, j);
        }

    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
                continue;
            }
            if(board[i][j] == '#'){
                board[i][j] = 'O';
            }            
        }
    }
}

int main(){
    vector<vector<char>> board ={{'O', 'X', 'X', 'X'},
                                 {'X',  'O', 'O', 'X'},
                                 {'X', 'O', 'O', 'X'},
                                 {'X', 'X', 'X', 'X'}};
    int m = board.size();
    int n = board[0].size();
    solve(board);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}