class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if(m==0) return result;
        int n = matrix[0].size();
        int top = 0, right = n-1, bottom = m-1, left = 0;
        int i = 0, j = 0, direction = 0; //direction:0-right, 1-down, 2-left, 3-up
        for(int iter=0; iter < m*n; iter++) {
            result.push_back(matrix[i][j]);
            switch(direction%4) {
                case 0: if(j!=right) j++; 
                        else {
                            direction++;
                            top++;
                            i++;
                        } break;
                case 1: if(i!=bottom) i++; 
                        else {
                            direction++;
                            right--;
                            j--;
                        } break;
                case 2: if(j!=left) j--; 
                        else {
                            direction++;
                            bottom--;
                            i--;
                        } break;
                case 3: if(i!=top) i--; 
                        else {
                            direction++;
                            left++;
                            j++;
                        } break;

            }
        }
        return result;
    }
};