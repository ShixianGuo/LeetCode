// @File   : jd-17.01_add.cpp
// @Source : https://leetcode-cn.com/problems/add-without-plus-lcci/
// @Title  : 面试题 17.01. 不用加号的加法
// @Auther : sun_ds
// @Date   : 2020/5/8

/**  题目描述：
    设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。

    示例:

    输入: a = 1, b = 1
    输出: 2
     

    提示：

    a, b 均可能是负数或 0
    结果不会溢出 32 位整数


    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/add-without-plus-lcci
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 *
 * 加法(不带进位) res = a ^ b;
 * 进位 c = (a & b) << 1;
 * 将res当做a，将c当做b继续执行。
 * 知道c==0，即没有进位了。
 *
 */

class Solution {
public:
    int add(int a, int b) {
        unsigned int res = 0;
        unsigned int c = 0;
        do{
            res = a ^ b;
            c = a & b;
            a = res;
            b = c<<1;
        }while(b!=0);
        return res;
    }
};
