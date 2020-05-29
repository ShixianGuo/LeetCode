/*和可被 K 整除的子数组
给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

 

示例：

输入：A = [4,5,0,-2,-3,1], K = 5
输出：7
解释：
有 7 个子数组满足其元素之和可被 K = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


//理解错误，没看清题意，以为非连续
void backtrack(vector<int> &A, int start, vector<vector<int>> &res, vector<int> &track, int K){
    if(track.size() != 0 && accumulate(track.begin(), track.end(), 0) % K == 0 && find(res.begin(), res.end(), track) == res.end()){
        res.push_back(track);
        return;
    }
    for(int i = start; i < A.size(); i++){
        track.push_back(A[i]);
        backtrack(A, i+1, res, track, K);
        track.pop_back();
    }
}
int subarraysDivByK(vector<int>& A, int K){
    vector<vector<int>> res;
    vector<int> track;
    backtrack(A, 0, res, track, K);
    for(auto nums:res){
        for(auto num:nums){
            cout << num << " ";
        }
        cout << endl;
    }
    return res.size();
}

int main(){
    vector<int> A = {4,5,0,-2,-3,1};
    int K = 5;

    cout << subarraysDivByK(A, K) << endl;

    return 0;
}