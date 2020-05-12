// @File   : 37_solveSudoku.cpp
// @Source : https://leetcode-cn.com/problems/sudoku-solver/
// @Title  : 37. 解数独
// @Auther : sun_ds
// @Date   : 2020/5/10

/**  题目描述：
    编写一个程序，通过已填充的空格来解决数独问题。

    一个数独的解法需遵循如下规则：

    数字 1-9 在每一行只能出现一次。
    数字 1-9 在每一列只能出现一次。
    数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
    空白格用 '.' 表示。



    一个数独。



    答案被标成红色。

    Note:

    给定的数独序列只包含数字 1-9 和字符 '.' 。
    你可以假设给定的数独只有唯一解。
    给定数独永远是 9x9 形式的。


    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/sudoku-solver
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.回溯法
 * 使用rows,cols,boxes记录每行、列、3*3宫内存在的数字。
 * 遍历。每个没有数字的位置，放置1~9，若满足规则，则递归到下一个位置，如果不满足条件则尝试其他数字，直到最后。
 *
 * 2.回溯法
 * 使用bitset压缩数据。
 * 每次回溯之前，选取最优的填充位置，即当前行、列、宫内都不包含的数字最小，所以填充时的选择也就更小，发生回溯的情况也就越少。
 * 使用cnt记录需要填充数字的个数，当cnt==0时，表示填充完毕。
 *
 *
 */

class Solution {
public:
    bool backtrack(vector<vector<char>>& board,vector<vector<bool>>& rows,vector<vector<bool>>& cols,vector<vector<bool>>& boxes){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.'){
                    for(int k=0;k<9;k++){
                        if(!rows[i][k]&&!cols[j][k]&&!boxes[i/3*3+j/3][k]){
                            rows[i][k] = cols[j][k] = boxes[i/3*3+j/3][k] = true;
                            board[i][j] = k + '1';
                            if(backtrack(board,rows,cols,boxes)) return true;
                            board[i][j] = '.';
                            rows[i][k] = cols[j][k] = boxes[i/3*3+j/3][k] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9,vector<bool>(9,false));
        vector<vector<bool>> cols(9,vector<bool>(9,false));
        vector<vector<bool>> boxes(9,vector<bool>(9,false));

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    int t = board[i][j] - '1';
                    rows[i][t] = cols[j][t] = boxes[i/3*3+j/3][t] = true;
                }
            }
        }
        backtrack(board,rows,cols,boxes);
    }
};



class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        //需要填充的个数
        int cnt = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        dfs(board, cnt);
    }

    bool dfs(vector<vector<char>>& board, int cnt)
    {
        if (cnt == 0) return true;//递归结束条件

        auto next = getNext(board);//找出可能性最小的位置（其实就是包含已知信息最多的位置，这样选择的次数是最少的，有点类似贪心的思想）

        auto bits = getPossibleStatus(next[0], next[1]);//找出这个坐标(i,j)可以填入的数字
        if(bits.count()==0) return false;

        for (int n = 0; n < bits.size(); n++)
        {
            //test取第n位
            if (!bits.test(n)) continue;
            fillNum(next[0], next[1], n, true);//更新存储状态
            board[next[0]][next[1]] = n + '1';

            if (dfs(board, cnt - 1)) return true;
            fillNum(next[0], next[1], n, false);//撤销上一步的存储状态
            board[next[0]][next[1]] = '.';
        }
        return false;
    }

    vector<int> getNext(vector<vector<char>>& board)
    {
        vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j);
                // 统计1的个数 即行列宫全是0的数的个数
                if (cur.count() >= minCnt) continue;
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret;
    }

    bitset<9> getPossibleStatus(int x, int y)
    {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    void fillNum(int x, int y, int n, bool fillFlag)
    {
        rows[x][n] = (fillFlag) ? (1) : (0);
        cols[y][n] = (fillFlag) ? (1) : (0);
        cells[x/3][y/3][n] = (fillFlag) ? (1): (0);
    }
private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};

