/*给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。*/

#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    res[0][0] = grid[m-1][n-1];
    for(int i = 1; i < m; i++){
        res[i][0] = res[i-1][0] + grid[i][0];
    }
    for(int j = 1; j < n; j++){
        res[0][j] = res[0][j-1] + grid[0][j];
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            res[i][j] = grid[i][j] + min(res[i-1][j], res[i][j-1]);
        }
    }
    return res[m-1][n-1];

}

int main(){
    vector<vector<int>> grid = {{1,3,1},
                                {1,5,1},
                                {4,2,1}};
    cout << minPathSum(grid) << endl;

    return 0;
}