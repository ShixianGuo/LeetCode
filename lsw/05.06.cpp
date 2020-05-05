class Solution {
public:
    int convertInteger(int A, int B) 
    {
       unsigned n = A^B;
       int res = 0;
       while(n)
       {
           ++res;
           n = n&(n-1);
       }
       return res;
    }
};
