// @File   : 54_spiralOrder.cpp
// @Source : https://leetcode-cn.com/problems/spiral-matrix/
// @Title  : 54. 螺旋矩阵
// @Auther : sun_ds
// @Date   : 2020/5/18

/**  题目描述：
    给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

    示例 1:

    输入:
    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
    输出: [1,2,3,6,9,8,7,4,5]
    示例 2:

    输入:
    [
      [1, 2, 3, 4],
      [5, 6, 7, 8],
      [9,10,11,12]
    ]
    输出: [1,2,3,4,8,12,11,10,9,5,6,7]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/spiral-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 螺旋矩阵
 * 模拟边界，l,r,t,b,为左右上下边界
 *
 * 修改完边界判断，是否break。
 *
 */


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0) return {};
        int n = matrix[0].size();
        vector<int> ans;
        int l=0,r=n-1,t=0,b=m-1;
        while(1){
            for(int i=l;i<=r;++i) ans.push_back(matrix[t][i]);
            if(++t>b) break;
            for(int i=t;i<=b;++i) ans.push_back(matrix[i][r]);
            if(--r<l) break;
            for(int i=r;i>=l;--i) ans.push_back(matrix[b][i]);
            if(--b<t) break;
            for(int i=b;i>=t;--i) ans.push_back(matrix[i][l]);
            if(++l>r) break;
        }
        return ans;
    }
};

