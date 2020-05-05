class Solution {
public:
    double myPow(double x, int n) 
    {
       double res = 1.0;
       int m = n;
       while(m)
       {
           if(m&0x01)
           {
               res *= x;
           }
           x*=x;
           m /= 2;
       }
       return n>0 ? res : 1.0/res;
    }
};
