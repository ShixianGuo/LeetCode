/*
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums){
    if(nums.size() == 0 || nums.size() == 1)
        return nums.size();

    unordered_set<int> s;
    for(auto num : nums)
        s.insert(num);
    int max_size = 0;
    for(auto n : s){
        int size = 1;
        n++;
        while(s.count(n)){
            size++;
            n++;
        }
        max_size = max(max_size, size);
    }
    return max_size;
}

int main(){
    vector<int> nums = {100, 4, 200, 1, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;

    return 0;
}