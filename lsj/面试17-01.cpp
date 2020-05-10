class Solution {
public:
    int add(int a, int b) {
        // if(b == 0) return a;
        // return add(a ^ b, ((unsigned int)a & b) << 1);
        while(b != 0) {
            int tmpa = a ^ b, tmpb = (unsigned int)(a & b) << 1;
            a = tmpa, b = tmpb;
        }
        return a;
    }
};
