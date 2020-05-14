class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int now=0;
        for(auto a:nums)
            now^=a;
        return now;
    }
};