/*一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
*/

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[0][0] == 1)
        return 0;
    vector<vector<int>> res(m, vector<int>(n, 0));
    res[0][0] = 1;
    for(int i = 1; i < m; i++){
        if(obstacleGrid[i][0] == 0 && res[i-1][0] == 1)
            res[i][0] = 1;
        else
            res[i][0] = 0;
    }
    for(int j = 1; j < n; j++){
        if(obstacleGrid[0][j] == 0 && res[j-1][0] == 1)
            res[0][j] = 1;
        else
            res[0][j] = 0;
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j] == 0)
                res[i][j] = res[i-1][j] + res[i][j-1];
            else
                res[i][j] = 0;
        }
    }
    return res[m-1][n-1];
}

int main(){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}