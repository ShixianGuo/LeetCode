#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int tmp = n ^ (n >> 1);
        // 检查tmp是否为全1的数
        return (tmp & ((long)tmp + 1)) == 0;
    }
};

