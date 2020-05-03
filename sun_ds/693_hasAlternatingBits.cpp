// @File   : 693_hasAlternatingBits.cpp
// @Source : https://leetcode-cn.com/problems/binary-number-with-alternating-bits/
// @Title  : 693. 交替位二进制数
// @Auther : sun_ds
// @Date   : 2020/5/3

/**  题目描述：
    给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。

    示例 1:

    输入: 5
    输出: True
    解释:
    5的二进制数是: 101
    示例 2:

    输入: 7
    输出: False
    解释:
    7的二进制数是: 111
    示例 3:

    输入: 11
    输出: False
    解释:
    11的二进制数是: 1011
     示例 4:

    输入: 10
    输出: True
    解释:
    10的二进制数是: 1010

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-number-with-alternating-bits
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 整数的低位二进制位是否是0，1交替。
 * 1.遍历
 *  从后往前遍历n的二进制位
 *  使用flag记录前一位是0还是1.
 *  使用flag_t记录当前位是0还是1.
 *  若flag == flag_t 则返回false.
 *
 *  遍历结束条件，temp>n，此时n的高位都是0了，不需要考虑了。
 *
 *
 * 2.位操作
 *  n的二进制位0，1交替。
 *  那么，即奇数位置和偶数位置应该是不相等的。
 *  比较n和(n>>1)，对应位上的情况。使用异或符号，n^(n>>1)，相同为0，不同为1.
 *  按照题目要求，异或完，低位应该全是1，而高位本来就是0，还是0.
 *
 *  此时需要判断temp的低位是否全是1.
 *
 *  如果temp低位全是1，那么temp+1必定使得低位全为0，并进位1.
 *  那么使用 temp&(temp+1) == 0是否成立，来判断低位是否全为1，即n的二进制位是否是0，1交替。
 *
 *
 *
 */
//逐位比较
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long temp = 1;
        bool flag = (temp&n)!=0; //注意优先级，要加括号
        temp <<= 1;
        while(temp<=n){
            bool flag_t = (temp&n)!=0;
            temp <<= 1;
            if(flag==flag_t) return false;
            flag = flag_t;
        }
        return true;
    }
};
//位操作
class Solution {
public:
    bool hasAlternatingBits(int n) {
        //下面有temp+1. 使用long long防止溢出
        long long temp = n^(n>>1);
        // n中二进制位应该是0，1交替的。将n左移一位，将相邻位置对上，然后进行异或。
        // 若满足0，1交替，必定异或完是1.
        // temp应该是低位(n的1的最高位之后)全是1.
        // 那么temp+1 必定是temp的低位全变0，进位1.
        // 那么此时，temp&(temp+1) == 0.
        return (temp&(temp+1)) == 0;
    }
};
