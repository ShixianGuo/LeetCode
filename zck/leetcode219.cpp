/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k){
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++){
        if(m.count(nums[i]) == 0){
            m[nums[i]] = i;
        }
        else{
            if(i - m[nums[i]] <= k)
                return true;
            else{
                m[nums[i]] = i;
            }
            
        }
    }
    return false;
}

int main(){
    vector<int> nums ={1,2,3,1,2,3};
    int k = 2;

    cout << containsNearbyDuplicate(nums, k) << endl;

    return 0;
}