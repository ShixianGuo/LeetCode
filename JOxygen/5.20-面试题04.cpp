class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return false;
        int m = matrix[0].size();
        if(!m) return false;
        int i = 0, j = m-1;
        while(i<n && j>=0) {
            int cur = matrix[i][j];
            if(cur == target) return true;
            else if(cur < target) {
                i++;
            } else if (cur > target) {
                j--;
            }
        }
        return false;
    }
};