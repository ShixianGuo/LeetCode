#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums){
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] > nums[i+1])
            return i;
    }
    return nums.size() - 1;
}

