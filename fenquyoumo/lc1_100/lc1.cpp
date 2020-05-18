class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int b=target-nums[i];
            //cout<<b<<mp[b]<<endl;
            if(mp[b]!=0)
            {
                //cout<<mp[b]<<i<<endl;
                res.push_back(mp[b]-1);
                res.push_back(i);
                return res;
            }
            else
            {
                mp[nums[i]]=i+1;
            }
        }
        return res;
    }
};