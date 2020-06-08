class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lst=n&1;
        n>>=1;
        while(n!=0)
        {
            if(lst==(n&1))
                return false;
            lst=n&1;
            n>>=1;
        }
        return true;
    }
};