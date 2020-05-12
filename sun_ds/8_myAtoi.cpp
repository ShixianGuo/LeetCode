// @File   : 8_myAtoi.cpp
// @Source : https://leetcode-cn.com/problems/string-to-integer-atoi/
// @Title  : 8. 字符串转换整数 (atoi)
// @Auther : sun_ds
// @Date   : 2020/5/10

/**  题目描述：
    请你来实现一个 atoi 函数，使其能将字符串转换成整数。

    首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

    当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

    该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

    注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

    在任何情况下，若函数不能进行有效的转换时，请返回 0。

    说明：

    假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

    示例 1:

    输入: "42"
    输出: 42
    示例 2:

    输入: "   -42"
    输出: -42
    解释: 第一个非空白字符为 '-', 它是一个负号。
         我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
    示例 3:

    输入: "4193 with words"
    输出: 4193
    解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
    示例 4:

    输入: "words and 987"
    输出: 0
    解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
         因此无法执行有效的转换。
    示例 5:

    输入: "-91283472332"
    输出: -2147483648
    解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
         因此返回 INT_MIN (−231) 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/string-to-integer-atoi
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 字符串转换整数
 * 从第一个非空格字符算起，可以为数字or'+'or'-'否则返回0。其次若'+'，'-'后不是数字也返回0。
 * 获取数字知道出现不是数字的字符或者字符串结束或者转换后的数越界结束。
 * 正常返回正常数字，越界返回INT_INT,INT_MAX
 *
 *
 * 注意判断越界方法
 *             if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
 *             if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
 *
 * 方法二中，都当正数算，最后去负号。
 * 所以中间判断仅使用
 * if(ans > INT_MAX/10||(ans == INT_MAX/10 && a > 7))
 * 不算错。因为，因为若他为-2147483648，a>7默认返回INT_MIN就是它本身！！！！若是，越界返回0那就不行了哦。
 * 比较特殊吧。
 *
 * 正常正反越界还是要区分的，毕竟差了一个值？
 *
 *
 * 使用字符串流去掉前后的空格
 * stringstream
 *
 */


class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        int i = 0;
        while(i<n && str[i]==' '){++i;}
        if(i == n) return 0;
        int ans = 0;

        if(str[i] == '+'){
            //下一位没有了或下一位不是数字
            if(++i == n || str[i] > '9'||str[i] < '0') return 0;
            while(i<n&&str[i]<='9'&&str[i]>='0'){
                //2147483647

                if(ans > (INT_MAX - (str[i] - '0'))/10)
                    return INT_MAX;
                ans = ans*10 + (str[i] - '0');
                ++i;
            }
        }else if(str[i] == '-'){
            if(++i == n || str[i] > '9'||str[i] < '0') return 0;
            while(i<n&&str[i]<='9'&&str[i]>='0'){
                //-2147483648
                if(ans < (INT_MIN + (str[i] - '0'))/10)
//                if(ans > -(INT_MIN - (str[i] - '0'))/10)
                    return INT_MIN;
                ans = ans*10 - (str[i] - '0');
                ++i;
            }
        }else if(str[i] <= '9'&&str[i] >= '0'){
            while(i<n&&str[i]<='9'&&str[i]>='0'){
                if(ans > (INT_MAX - (str[i] - '0'))/10)
                    return INT_MAX;
                ans = ans*10 + (str[i] - '0');
                ++i;
            }
        }else{
            return 0;
        }
        return ans;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        int i = 0;
        while(i<n && str[i]==' '){++i;}
        if(i == n) return 0;

        int flag = 0;
        if(str[i] == '+'){
            flag = 1;
            ++i;
        }else if(str[i] == '-'){
            flag = 0;
            ++i;
        }else if(str[i] > '9' || str[i] < '0') {
            return 0;
        }
        int ans = 0;
        while(i<n&&str[i]<='9'&&str[i]>='0'){
            int a = str[i++] - '0';
            //不需要if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;  if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            //直接a > 7就行。因为若他为-2147483648，a>7默认返回INT_MIN就是它本身！！！！若是，越界返回0那就不行了哦。
            if(ans > INT_MAX/10||(ans == INT_MAX/10 && a > 7)) return flag ? INT_MAX : INT_MIN;
            ans = ans*10 + a;
        }
        return flag ? ans : -ans;
    }
};


// stringstream 提取第一段 空格区分
class Solution {
public:
    int myAtoi(string str) {
        stringstream stream(str);
        string s;
        stream>>s;
        stream.clear();
        int flag = 0;
        int res = 0;
        if(s[0]=='-'){
            flag = 1;
        }else if(s[0]=='+'){
            flag = 0;
        }else{
            if(s[0]<'0'||s[0]>'9') return 0;
            else{
                res += s[0] - '0';
            }
        }
        for(int i=1;i<s.size();i++){
            if(s[i]<'0'||s[i]>'9'){
                break;
            }else{
                int t = s[i] - '0';
                if(res > INT_MAX/10||(res == INT_MAX/10 && t>7)) return flag ? INT_MIN:INT_MAX;
                res *= 10;
                res += t;
            }
        }
        return flag ? -res:res;
    }
};
