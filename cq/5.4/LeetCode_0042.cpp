class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size()) return 0;
        int l=0,r=height.size()-1;
        int maxl=0,maxr=0;
        int ans=0;
        while(l<r){
            if(height[l]>=height[r]){  //左边 ≥ 右边，更新右边
                height[r]>=maxr?maxr=height[r]:ans+=maxr-height[r];
                --r;
            }
            else{
                height[l]>=maxl?maxl=height[l]:ans+=maxl-height[l];
                ++l;
            }
        }
        return ans;
    }
};