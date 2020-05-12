class Solution {
    int Core(vector<int> &data,vector<int> &tmp, int l,int r){
        if(l==r) return 0;
        int mid=(r-l)>>1;
        int left=Core(tmp,data,l,l+mid);
        int right=Core(tmp,data,l+mid+1,r);
        
        int i=l+mid,j=r,tmpi=r;
        int cnt=0;
        while(i>=l&&j>=l+mid+1){
            if(data[i]>data[j]) {
                tmp[tmpi--]=data[i--];
                cnt+=j-l-mid;
            }
            else tmp[tmpi--]=data[j--];
        }
        while(i>=l) tmp[tmpi--]=data[i--];
        while(j>=l+mid+1) tmp[tmpi--]=data[j--];
        return left+right+cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2) return 0;
        vector<int> tmp(nums);
        return Core(nums,tmp,0,nums.size()-1);
    }
};