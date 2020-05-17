class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,maxNum=-1;
        for(int i=0;i<nums.size();++i){
            if(!cnt) {maxNum=nums[i];++cnt;}
            else if(maxNum==nums[i]) ++cnt;
            else --cnt;
        }
        return maxNum;
    }
};