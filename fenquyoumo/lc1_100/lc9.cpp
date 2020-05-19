class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x==0)return true;
        int num[100],cnt=0;
        while(x!=0)
        {
            num[cnt++]=x%10;
            x/=10;
        }
        for(int i=0;i<cnt/2;i++)
        {
            if(num[i]!=num[cnt-i-1])
                return false;
        }
        return true;
    }
};