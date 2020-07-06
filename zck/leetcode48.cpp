#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix){
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int temp = matrix[i][j];
            matrix[j][i] = temp;
            matrix[i][j] = temp;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++){
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}