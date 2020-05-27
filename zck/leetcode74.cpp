#include <iostream>
#include <vector>

using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target){
    int i = 0;
    int j = matrix[0].size() - 1;
    while(i <= matrix.size() && j >= 0){
        if(target > matrix[i][j]){
            i++;
        }
        else if(target < matrix[i][j]){
            j--;
        }
        else{
            return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};
    int target = 13;

    cout << searchMatrix(matrix, target) << endl;

    return 0;
}