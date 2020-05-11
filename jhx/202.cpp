/*
# 202. 快乐数

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为
1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <cassert>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
    unordered_set<int> s;

    int getN(int n) {
        int res = 0;
        while (n) {
            int k = n % 10;
            n /= 10;
            res += k * k;
        }
        return res;
    }

   public:
    bool isHappy(int n) {
        while (true) {
            if (s.count(n)) {
                return false;
            }
            s.insert(n);
            n = getN(n);
            if (n == 1) {
                return true;
            }
        }
    }
};

int main() {
    Solution s;
    assert(s.isHappy(19) == true);
}