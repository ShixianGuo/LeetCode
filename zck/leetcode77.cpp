/*给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int> nums, int start, vector<int> &track, int k, vector<vector<int>> &res){
    if(track.size() == k){
        res.push_back(track);
        return;
    }
    for(int i = start; i < nums.size(); i++){
        track.push_back(nums[i]);
        backtrack(nums, i + 1, track, k, res);
        track.pop_back();
    }
}

vector<vector<int>> combine(int n, int k){
    vector<int> nums;
    for(int i = 0; i < n; i++){
        nums.push_back(i + 1);
    }
    vector<vector<int>> res;
    vector<int> track;
    backtrack(nums, 0, track, k, res);

    return res;
}

int main(){
    vector<vector<int>> res = combine(4, 2);
    for(auto nums : res){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

//需要注意的是，vector push_back和赋值有区别