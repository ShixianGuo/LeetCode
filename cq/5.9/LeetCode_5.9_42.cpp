class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size()) return 0;
        int maxNum=INT_MIN;
        int tmp=0;
        for(auto it:nums){
            if(tmp<=0) tmp=it;
            else tmp+=it;
            maxNum=max(maxNum,tmp);
        }
        return maxNum;
    }
};