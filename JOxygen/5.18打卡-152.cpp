class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int minVal = nums[0], maxVal = nums[0], ans = nums[0];
        
        for(int i = 1; i < n; i++) {
            auto it = minmax({nums[i], nums[i]*minVal, nums[i]*maxVal});
            minVal = it.first;
            maxVal = it.second;
            ans = max(maxVal, ans);
        }
        return ans;
    }
};