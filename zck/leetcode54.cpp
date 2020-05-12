#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix){
    int upper = 0;
    int lower = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    vector<int> res;
    while(true){
        for(int i = left; i <= right; i++)
            res.push_back(matrix[upper][i]);
        if(++upper > lower)
            break;
        for(int i = upper; i <= lower; i++)
            res.push_back(matrix[i][right]);
        if(--right <left)
            break;
        for(int i = right; i>=left; i--)
            res.push_back(matrix[lower][i]);
        if(--lower < upper)
            break;
        for(int i = lower; i >=upper; i--)
            res.push_back(matrix[i][left]);
        if(++left > right)
            break;
    }
    return res;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = spiralOrder(matrix);
    for(auto r : res){
        cout << r << " ";
    }
    cout << endl;

    return 0;
}