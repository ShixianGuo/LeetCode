class Solution {
public:
    int reverse(int x) {
        int flag=0;
        if(x==INT_MIN) return 0;
        if(x<0){
            x=-x;
            flag=1;
        }
        long long ans=0;
        while(x){
            ans=ans*10+x%10;
            if(ans>INT_MAX||ans<INT_MIN) return 0;
            x/=10;
        }
        if(flag) ans=-ans;
        return (int)ans;
    }
};