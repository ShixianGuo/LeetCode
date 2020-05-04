class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
       int pre = n & 0x01;
       while(n)
       {
           n >>= 1;
           if(pre==(n&0x01))
           {
               return false;
           }
           pre = n&(0x01);
       }
       return true;
    }
};
