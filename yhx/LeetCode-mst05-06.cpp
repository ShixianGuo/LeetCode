class Solution {
public:
    int convertInteger(int A, int B) {
        int res = 0;
        unsigned int temp = A ^ B;
        while (temp) {
            res += ((temp & 1) == 0 ? 0 : 1);
            temp >>= 1;
        }
        return res;
    }
};
