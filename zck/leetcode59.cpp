/*给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>> res(n, vector<int>(n));
    vector<int> nums;
    for(int i = 1; i <= n * n; i++){
        nums.push_back(i);
    }

    int up = 0;
    int low = n - 1;
    int left = 0;
    int right = n - 1;
    
    int index = 0;
    while(true){
        //上侧 左到右
        for(int i = left; i <= right; i++){
            res[up][i] = nums[index];
            index++;
        }
        up++;
        if(up > low)
            break;
        //右侧 上到下
        for(int i = up; i <= low; i++){
            res[i][right] = nums[index];
            index++;
        }
        right--;
        if(left > right)
            break;

        //下侧 从右往左
        for(int i = right; i >= left; i--){
            res[low][i] = nums[index];
            index++;
        }
        low--;
        if(up > low)
            break;
        
        //左侧 下到上
        for(int i = low; i >= up; i--){
            res[i][left] = nums[index];
            index++;
        }
        left++;
        if(left > right)
            break;
    }
    return res;
}

int main(){

    int n = 3;
    vector<vector<int>> res = generateMatrix(n);

    for(auto nums : res){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}