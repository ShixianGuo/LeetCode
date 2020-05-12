class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> maxsums(nums.size());
        maxsums[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            maxsums[i] = max(maxsums[i - 1] + nums[i], nums[i]);
        }
        return *max_element(maxsums.begin(), maxsums.end());
    }
};
