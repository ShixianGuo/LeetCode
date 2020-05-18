class Solution {
    void printMat(vector<vector<int>> matrix, vector<int> &res, int m, int n, int start)
    {
        int endX = n - 1 - start;
        int endY = m - 1 - start;
        //从左到右打印一行
        for (int i = start; i <= endX; ++i)
            res.push_back(matrix[start][i]);
        //从上到下打印一行
        if (start < endY)
            for (int i = start + 1; i <= endY; ++i)
                res.push_back(matrix[i][endX]);
        //从右到左打印一行
        if (start < endY && start < endX)
            for (int i = endX - 1; i >= start; --i)
                res.push_back(matrix[endY][i]);
        //从下到上打印一行
        if (start < endY - 1 && start < endX)
            for (int i = endY - 1; i > start; --i)
                res.push_back(matrix[i][start]);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int start = 0;
        int m = matrix.size(), n = matrix[0].size();
        while (2 * start < m && 2 * start < n)
        {
            printMat(matrix, res, m, n, start);
            ++start;
        }
        return res;
    }
};