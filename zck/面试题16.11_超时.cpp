//回溯法超时

#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;
void backtrack(vector<int> nums, int k, vector<int>& track, set<int>& res){
    if(track.size() == k){
        int temp = accumulate(track.begin(), track.end(), 0); 
        res.insert(temp);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        track.push_back(nums[i]);
        backtrack(nums, k, track, res);
        track.pop_back();
    }
}
vector<int> divingBoard(int shorter, int longer, int k){
    vector<int> nums = {shorter, longer};
    vector<int> track;
    set<int> res;
    backtrack(nums, k, track, res);
    vector<int> ret;
    for(auto val : res){
        ret.push_back(val);
    }
    return ret;
}

int main(){
    vector<int> ret = divingBoard(1, 2, 3);
    for(auto val : ret)
        cout << val << " ";
    cout << endl;

    return 0; 
}