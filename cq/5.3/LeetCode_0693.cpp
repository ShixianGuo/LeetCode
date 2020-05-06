class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp=n^(n>>1);
        if(temp==INT_MAX) return true;
        return (temp&(temp+1))==0;
    }
};