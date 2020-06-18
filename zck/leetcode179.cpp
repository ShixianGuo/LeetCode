#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
**回溯法超时
**
void backtrack(vector<int>& nums, vector<bool> isUsed, vector<int>& track, vector<vector<int>>& res){
    if(track.size() == nums.size()){
        res.push_back(track);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(isUsed[i])
            continue;
        if(i > 0 && nums[i] == nums[i-1] && isUsed[i-1] == false) //去重
            continue;
        track.push_back(nums[i]);
        isUsed[i] = true;
        backtrack(nums, isUsed, track, res);
        track.pop_back();
        isUsed[i] = false;
    }
}

string largestNumber(vector<int>& nums){
    vector<int> track;
    vector<vector<int>> res;
    vector<bool> isUsed(nums.size(), false);

    backtrack(nums, isUsed, track, res);

    string max_string = "0";
    for(auto mat : res){
        string temp = "";
        for(auto m : mat)
            temp += to_string(m);
        max_string = max_string > temp? max_string : temp;
    }
    return max_string;
}

*/

bool Compare(string a, string b){
    return a + b > b + a;
}

string largestNumber(vector<int>& nums){
    vector<string> num_strs;
    for(auto num : nums)
        num_strs.push_back(to_string(num));
    sort(num_strs.begin(), num_strs.end(), Compare);
    if(num_strs[0] == "0")
        return "0";
        
    string res = "";
    for(auto str : num_strs)
        res += str;

    return res;
}
int main(){
    vector<int> nums = {1, 20, 311};
    cout << largestNumber(nums) << endl;
    return 0;
}

//