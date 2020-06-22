/*
*输入: [0,1,2,4,5,7]
*输出: ["0->2","4->5","7"]
*解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> summaryRanges(vector<int>& nums){
    vector<string> res;
    int i = 0;
    while(i < nums.size()){
        int j = i + 1;
        while(j < nums.size() && (j - i == nums[j] - nums[i]))
            j++;
        
        string temp;
        if(j - i == 1)
            temp = to_string(nums[i]);
        else
            temp = to_string(nums[i]) + "->" + to_string(nums[j-1]);
        res.push_back(temp);
        i = j;
    }
    return res;
}

int main(){
    vector<int> nums = {-2147483648,-2147483647,2147483647};
    vector<string> res = summaryRanges(nums);
    for(auto str : res)
        cout << str << " ";
    cout << endl;

    return 0;
}