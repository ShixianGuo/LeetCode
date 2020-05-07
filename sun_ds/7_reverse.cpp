// @File   : 7_reverse.cpp
// @Source : https://leetcode-cn.com/problems/reverse-integer/
// @Title  : 7. 整数反转
// @Auther : sun_ds
// @Date   : 2020/5/7


/**  题目描述：
    给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

    示例 1:

    输入: 123
    输出: 321
     示例 2:

    输入: -123
    输出: -321
    示例 3:

    输入: 120
    输出: 21
    注意:

    假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-integer
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



/**
 *
 * 整数反转，主要注意边界，不要溢出。
 * int 32位:
 *  INT_MAX = 2^31-1 = 2147483647, INT_MIN = -INT_MAX - 1 = -2^31 = -2147483648
 * 都是10位数，214开头，INT_MAX尾数为7，INT_MIN尾数为8
 *
 *
 *
 * 转换防溢出：
 *             if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
 *             if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
 *
 */


class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x){
            int temp = x % 10;
            x /= 10;
            //判断是否溢出
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && temp > 7)) return 0;
            if(res < INT_MIN / 10 || (res == INT_MIN / 10 && temp < -8)) return 0;
            res = res * 10 + temp;
        }
        return res;
    }
};

