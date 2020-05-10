class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int t1=1,t2=2;
        int ans;
        for(int i=3;i<=n;++i){
            ans=t1+t2;
            t1=t2;t2=ans;
        }
        return ans;
    }
};