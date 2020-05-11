// @File   : 36_isValidSudoku.cpp
// @Source : https://leetcode-cn.com/problems/valid-sudoku/
// @Title  : 36. 有效的数独
// @Auther : sun_ds
// @Date   : 2020/5/1

/**  题目描述：
    判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

    数字 1-9 在每一行只能出现一次。
    数字 1-9 在每一列只能出现一次。
    数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


    上图是一个部分填充的有效的数独。

    数独部分空格内已填入了数字，空白格用 '.' 表示。

    示例 1:

    输入:
    [
      ["5","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
    ]
    输出: true
    示例 2:

    输入:
    [
      ["8","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
    ]
    输出: false
    解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
         但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
    说明:

    一个有效的数独（部分已被填充）不一定是可解的。
    只需要根据以上规则，验证已经填入的数字是否有效即可。
    给定数独序列只包含数字 1-9 和字符 '.' 。
    给定数独永远是 9x9 形式的。


    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/valid-sudoku
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 1.暴力搜索
 *  对每个不为'.'的数都判断其行、列和九宫格中是否有与自己重复的元素。
 *  若存在这些位置上存在与自己相等的数，则不符合数独规则，返回false;
 *  否则，所有的数都遍历完，都满足规则，返回true;
 *
 *
 * 2.记录行、列、九宫格中出现过的数字 空间换时间
 *  使用rows，cols，boxes数组记录自己对应行、列、九宫格编号对应位置中的各个数字出现与否。
 *  遍历，若已经出现过，返回false；
 *  否则，在对应的行、列、九宫格中记录该数字出现过。
 *
 *  最终，如果都满足规则，返回true。
 *
 *
 */


class Solution {
public:
    bool isValid(vector<vector<char>>& board,int x, int y){
        char temp = board[x][y];
        //判断列
        for(int i=0;i<board.size();i++){
            if(i!=x && board[i][y]==temp) return false;
        }
        //判断行
        for(int i=0;i<board[0].size();i++){
            if(i!=y && board[x][i]==temp) return false;
        }
        //判断九宫格
        int x1 = x/3, y1 = y/3;
        for(int i = x1*3;i<x1*3+3;i++){
            for(int j=y1*3;j<y1*3+3;j++){
                if(i!=x&&j!=y&&board[i][j]==temp) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    if(!isValid(board,i,j)) return false;
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //记录行、列、九宫格中哪些数字出现过
        vector<vector<bool>> cols(9,vector<bool>(9,false));
        vector<vector<bool>> rows(9,vector<bool>(9,false));
        vector<vector<bool>> boxes(9,vector<bool>(9,false));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int temp = board[i][j] - '0' - 1;
                    if(rows[i][temp]) return false;
                    else rows[i][temp] = true;
                    if(cols[j][temp]) return false;
                    else cols[j][temp] = true;
                    int index = i/3*3 + j/3;
                    if(boxes[index][temp]) return false;
                    else boxes[index][temp] = true;
                }
            }
        }
        return true;
    }
};

