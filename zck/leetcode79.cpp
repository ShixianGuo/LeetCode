/*
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

word = "ABCCED", 返回 true
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(backtrack(board, word, 0, i , j)){ // 从二维表格的每一个格子出发
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string& word, int wordIndex, int x, int y){
        if( board[x][y] != word[wordIndex]){ // 当前位的字母不相等，此路不通
            return false;
        }
        if(word.size() - 1  == wordIndex){ // 最后一个字母也相等, 返回成功
            return true;
        }
        char tmp = board[x][y]; 
        board[x][y] = 0; // 避免该位重复使用
        wordIndex++;
        if((x > 0 && backtrack(board, word, wordIndex, x - 1, y)) // 往上走 (此处多谢笑川兄指正)
        || (y > 0 && backtrack(board, word, wordIndex, x, y - 1)) // 往左走
        || (x < board.size() - 1 && backtrack(board, word, wordIndex, x + 1, y)) // 往下走
        || (y < board[0].size() - 1 && backtrack(board, word, wordIndex, x, y + 1))){ // 往右走
            return  true; // 其中一条能走通，就算成功
        }
        board[x][y] = tmp; // 如果都不通，则回溯上一状态
        return false;
    }
};

