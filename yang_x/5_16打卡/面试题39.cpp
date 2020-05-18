////////投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        int x = nums[0];
        int vote = 1;
        for (int i = 1; i < nums.size(); ++i){
            if (vote == 0){
                x = nums[i];
            }
            if (nums[i] == x){
                vote++;
            }
            else{
                vote--;
            }
        }
        return x;
    }
};





////数组排序法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};