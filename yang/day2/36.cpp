class Solution {
public:
bool isValidSudoku(vector<vector<char>>& board) {
	char c[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			c[i][j] = board[j / 3 + (i / 3) * 3][(i % 3) * 3 + j % 3];
		}

	}
	for (int k = 0; k < 9; k++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				if (board[k][i] == board[k][j]&&board[k][j] != '.')
					return false;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = i + 1; j < 9; j++)
			{
				if (board[i][k] == board[j][k] && board[j][k]!='.')
				return false;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1 ; j < 9; j++)
			{
				if (c[k][i]==c[k][j] && c[k][i]!='.')
				return false;
			}
		}
	}
	return true;
}
};