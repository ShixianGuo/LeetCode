class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return {};
        int a = 0;      //定义上边界
        int m = matrix.size() - 1;      //定义下边界
        int b = 0;      //定义左边界
        int n = matrix[0].size() - 1;      //定义右边界
        vector<int> ans;
        while (true){
            for (int i = a; i <= n; ++i){
                ans.emplace_back(matrix[a][i]);
            }
            ++a;
            if (a > m)
                break;
            for (int i = a; i <= m; ++i){
                ans.emplace_back(matrix[i][n]);
            }
            --n;
            if (b > n)
                break;
            for (int i = n; i >= b; --i){
                ans.emplace_back(matrix[m][i]);
            }
            --m;
            if (a > m)
                break;
            for (int i = m; i >= a; --i){
                ans.emplace_back(matrix[i][b]);
            }
            ++b;
            if (b > n)
                break;
        }
        return ans;
    }
};