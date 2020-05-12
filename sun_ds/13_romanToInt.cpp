// @File   : 13_romanToInt.cpp
// @Source : https://leetcode-cn.com/problems/roman-to-integer/
// @Title  : 13. 罗马数字转整数
// @Auther : sun_ds
// @Date   : 2020/5/12

/**  题目描述：
    罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

    字符          数值
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

    通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
    给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

    示例 1:

    输入: "III"
    输出: 3
    示例 2:

    输入: "IV"
    输出: 4
    示例 3:

    输入: "IX"
    输出: 9
    示例 4:

    输入: "LVIII"
    输出: 58
    解释: L = 50, V= 5, III = 3.
    示例 5:

    输入: "MCMXCIV"
    输出: 1994
    解释: M = 1000, CM = 900, XC = 90, IV = 4.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/roman-to-integer
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 罗马数字转整数
 *
 * 两种情况，一个字符或者两个字符
 * 一个字符：
 * I             1
 * X             10
 * L             50
 * C             100
 * M             1000
 * 两个字符：
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900
 *
 * 使用map或者使用switch将单个罗马字符转换为数字。
 * 遍历罗马数字串，比较当前值和前一个值之间的大小关系。
 * 如果左边值大于右边值，正常。直接计入结果中。
 * 如果左边值小于右边值，不正常，计入结果中的值为右边值减去左边值。
 *
 *
 */

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        if (n==0)
            return 0;
        int res = 0;
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        if(n==1)
            return m[s[0]];

        int i=0;
        for(i=0;i<n-1;)
        {
            if (m[s[i]] < m[s[i+1]]){
                res +=  m[s[i+1]] - m[s[i]];
                i+=2;
            }else{
                res += m[s[i]];
                i++;
            }
        }
        if (i<=n-1){
            if (m[s[n-2]] < m[s[n-1]]){
                res -= m[s[n-2]];
                res += m[s[n-1]] - m[s[n-2]];
            }else{
                res += m[s[n-1]];
            }
        }

        return res;
    }
};


class Solution {
public:
    //使用switch时间空间都优于map
    int getValue(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        int n = s.size();
        int pre = getValue(s[0]);
        int res = pre;
        for(int i=1;i<n;i++){
            int cur = getValue(s[i]);
            if(cur > pre){
                res += cur - 2*pre;
            }else{
                res += cur;
            }
            pre = cur;
        }
        return res;
    }
};