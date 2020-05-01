
/*
Leetcode36
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-sudoku
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		int cloumns[9][10] = { 0 };//9列，每列10个数字
		int boxes[9][10] = { 0 };//9个box，每个box10个数字
		int num = 0;
		for (int i = 0; i < 9; ++i) {
			int row[10] = { 0 };//按行扫描，每行可以复用

			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					continue;
				}
				num = board[i][j] - '0';
				//判断
				if (row[num] > 0)
					return false;
				if (cloumns[j][num] > 0)
					return false;
				//(4,0)代入box序号为3
				if (boxes[i / 3 * 3 + j / 3][num] > 0)
					return false;

				//未出现过
				row[num]++;
				cloumns[j][num]++;
				boxes[i / 3 * 3 + j / 3][num]++;
			}
		}
		return true;
	}
};