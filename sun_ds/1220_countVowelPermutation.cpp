// @File   : 1220_countVowelPermutation.cpp
// @Source : https://leetcode-cn.com/problems/count-vowels-permutation/
// @Title  : 1220. 统计元音字母序列的数目
// @Auther : sun_ds
// @Date   : 2020/5/6


/**  题目描述：
    给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：

    字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
    每个元音 'a' 后面都只能跟着 'e'
    每个元音 'e' 后面只能跟着 'a' 或者是 'i'
    每个元音 'i' 后面 不能 再跟着另一个 'i'
    每个元音 'o' 后面只能跟着 'i' 或者是 'u'
    每个元音 'u' 后面只能跟着 'a'
    由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。

     

    示例 1：

    输入：n = 1
    输出：5
    解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
    示例 2：

    输入：n = 2
    输出：10
    解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和 "ua"。
    示例 3：

    输入：n = 5
    输出：68
     

    提示：

    1 <= n <= 2 * 10^4

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/count-vowels-permutation
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*
 *
 * 简单的动态规划问题
 * 通过给出的字符的排列规则，构建状态转移方程
 * 最终得出结果
 *
 * 注意结果可能越界，需要对模 10^9 + 7取模，取模的位置要注意，保证不能越界。
 *
 */

#include <iostream>

using namespace std;


class Solution {
public:
    const long long MAXN = 1e9+7;
    int countVowelPermutation(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 5;
        long long dp[5] = {1,1,1,1,1};
        for(int i=2;i<=n;i++)
        {
            int d_a = (dp[1] + dp[2] + dp[4]) % MAXN;
            int d_e = (dp[0] + dp[2]) % MAXN;
            int d_i = (dp[1] + dp[3]) % MAXN;
            int d_o = (dp[2]) % MAXN;
            int d_u = (dp[2] + dp[3]) % MAXN;

            dp[0] = d_a;
            dp[1] = d_e;
            dp[2] = d_i;
            dp[3] = d_o;
            dp[4] = d_u;
        }
        long long res = 0;
        for(int i=0;i<5;i++)
        {
            res += dp[i];
        }
        return res % MAXN;
    }
};