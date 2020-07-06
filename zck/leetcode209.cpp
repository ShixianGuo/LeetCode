/*
*输入: s = 7, nums = [2,3,1,2,4,3]
*输出: 2
*解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
int minSubArrayLen(int s, vector<int>& nums){

    if(nums.size() == 0)
        return 0;
    if(nums.size() == 1)
        if(nums[0] >= s)
            return 1;
        else
            return 0;

    if(nums[0] > s)
        return 1;

    int i = 0, j = 1;
    int sumSubArray = nums[i] + nums[j];
    int min_len = INT32_MAX;

    while(j < nums.size()){
        if(sumSubArray < s){
            j++;
            if(j < nums.size()){
                sumSubArray += nums[j];
            }
        }
        else{
            min_len = min(min_len, j - i + 1);
            sumSubArray -= nums[i];
            i++;
        }
    }
    if(min_len == INT32_MAX)
        return 0;
    return min_len;
}

};