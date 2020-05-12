// @File   : 12_intToRoman.cpp
// @Source : https://leetcode-cn.com/problems/integer-to-roman/
// @Title  : 12. 整数转罗马数字
// @Auther : sun_ds
// @Date   : 2020/5/12

/**  题目描述：
    罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

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
    给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

    示例 1:

    输入: 3
    输出: "III"
    示例 2:

    输入: 4
    输出: "IV"
    示例 3:

    输入: 9
    输出: "IX"
    示例 4:

    输入: 58
    输出: "LVIII"
    解释: L = 50, V = 5, III = 3.
    示例 5:

    输入: 1994
    输出: "MCMXCIV"
    解释: M = 1000, CM = 900, XC = 90, IV = 4.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/integer-to-roman
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 * 整数转罗马数字。
 * 先定义好对应罗马数字取值
 *
 * 将输入数字与对应罗马数字取值比较(从大到小)
 * 并依次将罗马数字添加到结果中去。
 * 注意有些字符可能会重复多次。
 *
 * 1.使用vector，并求出确切的temp/n[i]，然后加上temp/n[i]个s[i]，两层循环？
 * 2.使用数组，不求出temp/n[i]，只是比较temp与n[i]的大小。通过循环来控制需要多少个。
 *
 */



class Solution {
public:
    string intToRoman(int num) {
        vector<int> n{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> s{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int temp = num;
        int i = 0;
        string ans;
        while(!temp/n[i]){++i;}
        while(temp){
            int div =  temp/n[i];
            for(int j=0;j<div;j++){
                ans += s[i];
            }
            temp -= n[i]*div;
            ++i;
        }
        return ans;
    }
};


class Solution {
public:
    string intToRoman(int num) {
        int n[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans;
        for(int i=0;i<13;i++){
            while(num>=n[i]){
                ans += s[i];
                num -= n[i];
            }
        }
        return ans;
    }
};