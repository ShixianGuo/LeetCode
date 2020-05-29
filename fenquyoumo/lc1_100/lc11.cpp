class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int len=j;
        int ans=0;
        while(i<j)
        {
            int res=len*min(height[i],height[j]);
            len--;
            ans=max(ans,res);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};