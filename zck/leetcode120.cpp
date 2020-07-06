/*给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

 

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
*/
#include <iostream>
#include <vector>

using namespace std;


//自底向上
int minimumTotal(vector<vector<int>>& triangle){
    int n = triangle.size();
    for(int row = n - 2; row >= 0; row--){
        for(int col = 0; col < triangle[row].size(); col++){
            triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col + 1]);
        }
    }
    return triangle[0][0];
}

int main(){
    vector<vector<int>> triangle = {{2},
                                    {3,4},
                                    {6,5,7},
                                    {4,1,8,3}};

    cout << minimumTotal(triangle) << endl;

    return 0;
}
