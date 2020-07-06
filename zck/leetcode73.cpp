/*给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
*/

#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                for(int t = 0; t < n; t++){
                    if(matrix[i][t] == 0)
                        continue;
                    matrix[i][t] = '#';
                }
                for(int p = 0; p < m; p++){
                    if(matrix[p][j] == 0)
                        continue;
                    matrix[p][j] = '#';
                }
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == '#')
                matrix[i][j] = 0;
        }
    }
}

//有一个case没过