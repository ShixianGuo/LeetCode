/*给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows){

    if(numRows == 0)
        return {};

    vector<vector<int>> res;
    res.push_back({1});
    for(int i = 1; i < numRows; i++){
        vector<int> temp;
        temp.push_back(1);
        for(int j = 0; j < res[i-1].size() - 1; j++){
            temp.push_back(res[i-1][j] + res[i-1][j+1]);
        }
        temp.push_back(1);
        res.push_back(temp);
    }
    return res;
}

vector<int> getRow(int rowIndex){
    vector<vector<int>> res = generate(rowIndex + 1);
    return res.back();
}

int main(){
    int numRows = 4;
    vector<vector<int>> res = generate(numRows);
    for(auto nums : res){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
