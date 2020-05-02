/*
 * 通过一次遍历，统计各行、各列、各个方块中1-9的个数，一但发现超过1，则错误。
 * 使用3*9=27个1*9的int数组实现统计；
 */

#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int lineCount[9][9] = {0};
        int columnCount[9][9] = {0};
        int blockCount[9][9] = {0};
        for(int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    if (lineCount[i][num] != 0)
                        return false;
                    else
                        lineCount[i][num] = 1;

                    if (columnCount[j][num] != 0)
                        return false;
                    else
                        columnCount[j][num] = 1;

                    if (blockCount[(i / 3) * 3 + j / 3][num] != 0)
                        return false;
                    else
                        blockCount[(i / 3) * 3 + j / 3][num] = 1;
                }
            }
        }
        return true;
    }
};

