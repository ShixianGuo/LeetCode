// @File   : 233_countDigitOne.cpp
// @Source : https://leetcode-cn.com/problems/number-of-digit-one/
// @Title  : 233. 数字 1 的个数
// @Auther : sun_ds
// @Date   : 2020/5/16

/**  题目描述：
    给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

    示例:

    输入: 13
    输出: 6
    解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/number-of-digit-one
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 *
 * 1.公式法
 *  个位数1的个数 (n/10)*1+min(max(n%10-1+1,0),1)
 *  十位数1的个数 (n/100)*10+min(max(n%100-10+1,0),10)
 *      前部分是每100个数出10个十位为1 即11，12,...,19，十位的10个1.后面判断不够整百的有没有超过11，12,...,19的，统计进来
 *  百位数1的个数 (n/1000)*100+min(max(n%1000-100+1,0),100)
 *      前部分是每1000个数出100个十位为1 即100，101,...,199，百位的100个1.后面判断不够整千的有没有超过100，101,...,199的，统计进来
 *
 * 2.递归
 * 将n转换为字符串(方便获得最高位，str[0])
 * 除掉高位剩下的是last
 *
 * 如果高位为1
 *  如n=1234 str[0] = 1 p = 1000 last = 234
 *  递归dfs(p-1)+dfs(last)+(last+1)
 *     dfs(p-1)代表 [0-999]中1出现的次数 dfs(last) 代表[1001，1234]中的非高位1出现的次数 last+1 代表[1000，1234]最高位1的个数
 * 如果高位为非1
 *  如n=2345 str[0] = 2 p = 1000 last = 345
 *  递归p + high * dfs(p - 1) + dfs(last)
 *  high * dfs(p-1)代表 [0-999，1000-2000]中1出现的次数(不含最高位) dfs(last) 代表[2001，2345]中的非高位1出现的次数
 *  p代表代表[1000，2345]中最高位1的个数 必定为p=1000个
 *
 *
 */

//公式法
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for(long long i=1;i<=n;i*=10){
            res += (n/(i*10)*i)+min(max(n%(i*10)-i+1,0LL),i);
        }
        return res;
    }
};

//递归
class Solution {
public:
    int dfs(int n) {
        if (n <= 0) {
            return 0;
        }
        string numStr = to_string(n);
        int high = numStr[0] - '0';
        int p = (int)pow(10, numStr.size() - 1);
        int last = n - high * p;

        if (high == 1) {
            // 最高位是1，如1234, 此时p = 1000,那么结果由以下三部分构成：
            // (1) dfs(p - 1)代表[0,999]中1的个数;
            // (2) dfs(last)代表234中1出现的个数;
            // (3) last+1代表固定高位1有多少种情况。
            return dfs(p - 1) + dfs(last) + last + 1;
        } else {
            // 最高位不为1，如2234，那么结果也分成以下三部分构成：
            // (1) p代表固定高位1，有多少种情况;
            // (2) high * dfs(p - 1)代表999以内和1999以内低三位1出现的个数;
            // (3) dfs(last)同上。
            return p + high * dfs(p - 1) + dfs(last);
        }
    }
    int countDigitOne(int n) {
        return dfs(n);
    }
};