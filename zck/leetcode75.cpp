/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortColors(vector<int>& nums){
    int p0 = 0, cur = 0, p2 = nums.size() - 1;
    while(cur <= p2){
        if(nums[cur] == 0){
            swap(nums[cur], nums[p0]);
            p0++;
            cur++;
        }
        else if(nums[cur] == 2){
            swap(nums[cur], nums[p2]);
            p2--;
        
        }
        else
            cur++;
    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(auto num : nums){
        cout << num << " ";
    }
    return 0;
}