class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int idx=0;
        int n=nums.size();
        while(idx<n){
            if(nums[idx]==idx+1) ++idx;
            else if(nums[idx]<idx+1||nums[idx]>n||nums[nums[idx]-1]==nums[idx])
                nums[idx]=nums[--n];
            else swap(nums[nums[idx]-1],nums[idx]);
        }
        return idx+1;
    }
};