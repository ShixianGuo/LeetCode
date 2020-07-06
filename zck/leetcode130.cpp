/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<char>> & board, int i, int j){
    int m = board.size();
    int n = board[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        int row = temp.first;
        int col = temp.second;
        if(row + 1 < m && board[row + 1][col] == 'O'){
            q.push({row + 1, col});
            board[row + 1][col] = '#';
        }
        if(row - 1 >= 0 && board[row - 1][col] == 'O'){
            q.push({row - 1, col});
            board[row - 1][col] = '#';
        }
        if(col + 1 < n && board[row][col + 1] == 'O'){
            q.push({row, col + 1});
            board[row][col + 1] = '#';
        }
        if(col - 1 >= 0 && board[row][col - 1] == 'O'){
            q.push({row, col - 1});
            board[row][col - 1] = '#';
        }
    }
}

void solve(vector<vector<char>>& board){
    int m = board.size();
    if(m == 0)
        return;
    int n = board[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if((i == 0 || i == m - 1 || j == 0 || j == n -1) && board[i][j] == 'O'){
                board[i][j] = '#';
                bfs(board, i, j);
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '#'){
                board[i][j] = 'O';
                continue;
            }
            if(board[i][j] == 'O'){
                board[i][j] = 'X'; 
                continue;
            }  
        }
    }
}

int main(){
    vector<vector<char>> board ={{'O', 'X', 'X', 'X'},
                                 {'X',  'O', 'O', 'X'},
                                 {'X', 'O', 'O', 'X'},
                                 {'X', 'O', 'O', 'X'}};
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