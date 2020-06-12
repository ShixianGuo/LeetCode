/*
*输入: [3,4,5,1,2]
*输出: 1
*/

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums){
    int left = 0, right = nums.size() - 1;
    while(left < right){
        int mid = (left + right) / 2;
        int tmp = nums[mid];
        if(tmp >= nums[0]){
            left = mid + 1;
        }
        else{
           right = mid;
        }
    }
    return nums[0] < nums[left]? nums[0]:nums[left];
}