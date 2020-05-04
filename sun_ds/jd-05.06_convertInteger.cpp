// @File   : jd-05.06_convertInteger.cpp
// @Source : https://leetcode-cn.com/problems/convert-integer-lcci/
// @Title  : 面试题 05.06. 整数转换
// @Auther : sun_ds
// @Date   : 2020/5/4

/**  题目描述：
    整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。

    示例1:

     输入：A = 29 （或者0b11101）, B = 15（或者0b01111）
     输出：2
    示例2:

     输入：A = 1，B = 2
     输出：2
    提示:

    A，B范围在[-2147483648, 2147483647]之间

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/convert-integer-lcci
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 核心，统计二进制位为1的个数。
 * 1.temp&temp-1
 *  消掉temp后面的第一个1.
 *
 * 2.temp&-temp
 * 获取temp的lowbit，即lowbit只包含temp最后面的一个1，其他位置都为0.
 * 使用 temp & (~lowbit) = temp &(~(temp&-temp));
 *
 *
 */

class Solution {
public:
    int convertInteger(int A, int B) {
        //使用无符号记录各个位，防止temp-1越界 如temp=INT_MIN
        //使用无符号不会越界，因为temp-1越界即temp=0.此时while不通过。
        unsigned int temp = A ^ B;
        int res = 0;
        while (temp != 0) {
            temp &= (temp - 1);  // 去掉二进制表示的最右边的1
            res++;
        }
        return res;
    }
};

class Solution {
public:
    int convertInteger(int A, int B) {
        //使用无符号记录各个位，防止-temp越界 如temp=INT_MIN
        //使用无符号不会越界，当temp=INT_MIN，时，temp = -temp，对于unsigned int类型。
        unsigned int temp = A ^ B;
        int res = 0;
        while (temp != 0) {
            temp &= ~(temp&-temp);  // 去掉二进制表示的最右边的1
            res++;
        }
        return res;
    }
};
