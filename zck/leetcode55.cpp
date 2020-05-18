#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int>& nums){
    int start  = 0;
    if(nums.size() == 1)
        return true;
    if(nums[start] == 0)
        return false;
    while(start < nums.size()){
        int len = nums[start];
        if(len + start >= nums.size() - 1)
            return true;
        vector<int> temp;
        for(int i = start + 1; i < len + start + 1; i++){
            temp.push_back(nums[i] + i);
        }
        int max_index = max_element(temp.begin(), temp.end()) - temp.begin();
        start = max_index + start + 1;
        if(nums[start] == 0)
            return false;
    }
    return true;
}


/*输入: [2,3,1,1,4]
输出: true */

/*输入: [3,2,1,0,4]
输出: false */

int main(){
    vector<int> temp = {3, 2, 1, 0, 4};
    cout << canJump(temp) << endl;
    return 0;
}