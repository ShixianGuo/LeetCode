/*假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
*/
#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target){
    if(target == nums[0] || target == nums.back())
        return true;

    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] < target){
            if(target < nums.back()){
                left = mid + 1;
                right = right - 1;
            }
            else{
                right = mid - 1;
                left = left + 1;
            }
        }
        else if(nums[mid] > target){
            if(target > nums.back()){
                right = mid - 1;
                left = left + 1;
            }
            else{
                left = mid + 1;
                right = right - 1; 
            }
        }
        else{
            return true;
        }
        
    }
    return false;
}

int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 3;

    cout << search(nums, target) << endl;

    return 0;
}

//257/275,不能过所有case 