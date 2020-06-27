/*给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
示例 1:
输入: [1,2,0]
输出: 3
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int firstMissingPositive(vector<int>& nums){
    unordered_multiset<int> vals;
    for(auto num : nums){
        vals.insert(num);
    }
    int i = 1;
    while(vals.count(i) != 0)
        i++;
    return i;
}

int main(){
    vector<int> nums = {7,8,9,11,12};
    cout <<  firstMissingPositive(nums) << endl;

    return 0;

}