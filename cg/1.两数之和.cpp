/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int temp = target - nums[i];
            if(m.find(temp) != m.end()){
                res.push_back(i);
                res.push_back(m[temp]);
            }
            else
            {
                m[nums[i]] = i;
            }
            
        }
        return res;
    }
};
// @lc code=end

