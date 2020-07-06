#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


//全排列做的，结果不对，也存在超时

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

double new21Game(int N, int K, int W){
    vector<int> nums;
    for(int i = 1; i <= W; i++){
        nums.push_back(i);
    }
    vector<vector<int>> res;
    vector<int> track;
    backtrack(nums, track, res);

    int count = 0;
    for(auto nums : res){
        int sum = 0;
        for(auto num : nums){
            sum += num;
            if(sum >= K){
                if(sum <= N)
                    count++;
                break;
            }
        }
    }
    return count / double(res.size());
}

int main(){
    int N = 21;
    int K = 17;
    int W = 10;
    
    cout << new21Game(N, K, W) << endl;

    return 0;
}