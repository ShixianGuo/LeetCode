class Solution {
public:
    int add(int a, int b) {
        int sum,carry;
        do{
            sum=a^b;
            carry=(unsigned int)(a&b)<<1;
            a=sum,b=carry;
        }while(carry);
        return sum;
    }
};