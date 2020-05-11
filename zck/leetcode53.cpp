class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, res = nums[0];
        for(auto num : nums){
            pre = max(pre + num, num);
            res = max(pre, res);
        }
        return res;
    }
};