class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return {};
        int top = 0, bot = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        vector<int> res;

        while(true) {
            for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);
            if(++top > bot) break;
            for(int i = top; i <= bot; i++) res.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; i--) res.push_back(matrix[bot][i]);
            if(--bot < top) break;
            for(int i = bot; i >= top; i--) res.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return res;
    }
};
