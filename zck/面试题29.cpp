/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix){
    if(matrix.size() == 0)
        return {};
    int left = 0;
    int right = matrix[0].size() - 1;

    int up = 0;
    int low = matrix.size() - 1;

    vector<int> res;
   
    while(true){
        for(int i = left; i <= right; i++)
            res.push_back(matrix[up][i]);
        up++;
        if(up > low)
            break;
            
        for(int i = up; i <= low; i++){
            res.push_back(matrix[i][right]);
        }
        right--;
        if(right < left)
            break;

        for(int i = right; i >= left; i--){
            res.push_back(matrix[low][i]);
        }
        low--;
        if(low < up)
            break;
        

        for(int i = low; i >= up; i--){
            res.push_back(matrix[i][left]);
        }
        left++;
        if(right < left)
            break;
    }
    return res;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    
    vector<int> res = spiralOrder(matrix);
    for(auto num : res){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}