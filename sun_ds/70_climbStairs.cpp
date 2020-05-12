// @File   : 70_climbStairs.cpp
// @Source : https://leetcode-cn.com/problems/climbing-stairs/
// @Title  : 70. 爬楼梯
// @Auther : sun_ds
// @Date   : 2020/5/10

/**  题目描述：
    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

    注意：给定 n 是一个正整数。

    示例 1：

    输入： 2
    输出： 2
    解释： 有两种方法可以爬到楼顶。
    1.  1 阶 + 1 阶
    2.  2 阶
            示例 2：

    输入： 3
    输出： 3
    解释： 有三种方法可以爬到楼顶。
    1.  1 阶 + 1 阶 + 1 阶
    2.  1 阶 + 2 阶
    3.  2 阶 + 1 阶

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/climbing-stairs
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 * 爬楼梯
 *
 * 动态规划
 * dp[n] = dp[n-1] + dp[n-2]
 * dp[1]=1
 * dp[2]=2
 *
 * 滚动数组压缩
 * 可以不用数组dp[n]，节约空间复杂度
 *
 * 斐波那契数列
 *
 *
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)
            return 1;
        int dp[n+1];
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int t1 = 1,t2 = 2;
        for(int i=3;i<=n;i++){
            int temp = t1 + t2;
            t1 = t2;
            t2 = temp;
        }
        return t2;
    }
};
