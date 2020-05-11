#pragma once
#include"entity.h"
using namespace std;



/*
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	int rows[9][10] = { 0 };
	int cols[9][10] = { 0 };
	int boxes[9][10] = { 0 };

	bool backTrace(int row, int col, vector<vector<char>>& board) {
		//如果是数字，寻找坑
		while (board[row][col] != '.') {
			if (col < 8) {
				++col;
			}
			else if (row < 8) {
				++row;
				col = 0;
			}
			else {
				return true;
			}
		}
		//开始填数字,从1开始尝试
		int flag = false;
		for (int n = 1; n <= 9; ++n) {
			if (rows[row][n] == 0 && cols[col][n] == 0 && boxes[row / 3 * 3 + col / 3][n] == 0) {
				++rows[row][n];
				++cols[col][n];
				++boxes[row / 3 * 3 + col / 3][n];
				board[row][col] = ('0' + n);
				if (col < 8) {
					flag = backTrace(row, col + 1, board);
				}
				else if (row < 8 && col == 8) {
					flag = backTrace(row + 1, 0, board);
				}
				else {
					//边界
					return true;
				}

				if (flag == true) {
					return true;
				}
				//这里不能放n，回退换下个n
				--rows[row][n];
				--cols[col][n];
				--boxes[row / 3 * 3 + col / 3][n];
				board[row][col] = '.';
			}
		}
		//如果都不行
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		//统计哈希
		int num = 0;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					num = board[i][j] - '0';
					++rows[i][num];
					++cols[j][num];
					++boxes[i / 3 * 3 + j / 3][num];

				}
			}
		}
		//回溯法
		backTrace(0, 0, board);

	}
};