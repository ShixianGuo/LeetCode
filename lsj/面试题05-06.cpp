class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned x = A ^ B; //必须使用 unsigned
        // 然后就是计算 x 中 1 的个数了
        int cnt = 0;
        while(x != 0) {
            x &= (x - 1);
            cnt++;
        }
        return cnt;
    }
};
