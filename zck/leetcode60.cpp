/*给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void backtrack(vector<int> nums, vector<int> &track, vector<vector<int>> &res){
    if(track.size() == nums.size()){
        res.push_back(track);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(find(track.begin(), track.end(), nums[i]) != track.end())
            continue;
        track.push_back(nums[i]);
        backtrack(nums, track, res);
        track.pop_back();
    }
}

string getPermutation(int n, int k){
    vector<int> nums;
    for(int i = 1; i <= n; i++)
        nums.push_back(i);
    vector<vector<int>> res;
    vector<int> track;
    backtrack(nums, track, res);

    string s = "";
    for(auto num : res[k-1]){
        s += (num + '0');
    }
    return s;
}

int main(){
    int n = 3;
    int k = 3;
    cout << getPermutation(n, k) << endl;

    return 0;
}