/*
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
    vector<int> L(nums.size(), 1);
    L[0] = 1;
    for(int i = 1; i < nums.size(); i++){
        L[i] = L[i-1] * nums[i-1];
    }

    vector<int> R(nums.size(), 1);
    for(int j = nums.size() - 2; j >= 0; j--){
        R[j] = R[j+1] * nums[j+1];
    }
    for(int k = 0; k < nums.size(); k++){
        nums[k] = L[k] * R[k];
    }
    return nums;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = productExceptSelf(nums);
    for(auto num : res){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}