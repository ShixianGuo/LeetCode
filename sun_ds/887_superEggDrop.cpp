// @File   : 887_superEggDrop.cpp
// @Source : https://leetcode-cn.com/problems/super-egg-drop/
// @Title  : 887. 鸡蛋掉落
// @Auther : sun_ds
// @Date   : 2020/5/8

/**  题目描述：
    你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。

    每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。

    你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。

    每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。

    你的目标是确切地知道 F 的值是多少。

    无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？

     

    示例 1：

    输入：K = 1, N = 2
    输出：2
    解释：
    鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
    否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
    如果它没碎，那么我们肯定知道 F = 2 。
    因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
    示例 2：

    输入：K = 2, N = 6
    输出：3
    示例 3：

    输入：K = 3, N = 14
    输出：4
     

    提示：

    1 <= K <= 100
    1 <= N <= 10000


    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/super-egg-drop
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 *
 *
 * 1.dp
 * dp[i][j] 表示i个蛋，j高度的楼层最少需要的移动次数。
 * 假设当前在k层楼(1<=k<=j)扔鸡蛋。
 *  碎了，F应该在[1,k-1]楼层取出，并且鸡蛋碎了，鸡蛋数量减少 有dp[i][j] = 1 + dp[i-1][k-1].
 *  没碎，F应该在[k+1,j]楼层取出，并且鸡蛋没碎，鸡蛋数量不变 有dp[i][j] = 1 + dp[i][j-k]. ([k+1,j]楼层可以把k+1看成1楼，分解子问题。则j楼变为j-k高度)
 * 由于不知道会不碎所以最坏情况是去个最大值， 1+max(dp[i-1][k-1],dp[i][j-k])
 *
 * 除此之外，k这个楼层也是随机取的。即在范围内k都可以取。
 * 为了使最坏情况移动次数最少。即遍历k个位置，找到各个k对应的最大值的最小值。
 * 即 min(1+max(dp[i-1][k-1],dp[i][j-k])).作为当前i个数蛋和j层楼最少需要的移动次数。
 *
 * 分析边界条件。
 * 0颗蛋和0层楼，都没有意义，设置为0 。
 * 1颗蛋测出对应的F值。只能采取从低楼层到高楼层遍历的方式，即从1层开始，若没碎从2楼开始，若碎了则F=0层。
 * 所以对于j层楼，1颗蛋。需要的最少移动次数为j。
 * 1层楼，i个蛋，则只需要一次，测试一下1层是否会碎。
 * 初始化dp矩阵，在每个楼层移动的最大次数就是当前楼层数。
 *
 * 最终得到结果dp[K][N]即为最终结果
 *
 * 时间复杂度O(K*N^2)
 *
 *
 * 2.dp+二分
 *  我们观察到 dp(K,N) 是一个关于 N 的单调递增函数，也就是说在鸡蛋数 K 固定的情况下，楼层数 N 越多，需要的步数一定不会变少。
 *  在上述的状态转移方程中:
 *  第一项 T1(X)=dp(K−1,X−1) 是一个随 X 的增加而单调递增的函数
 *  第二项 T2(X)=dp(K,N−X) 是一个随着 X 的增加而单调递减的函数
 *
 * 因此，使得max(T1,T2)最小。即取T1=T2处。由于，T1、T2是离散函数，所以取距离函数交点最近的左右两个能取到的点。找到使得max(T1,T2)最小的位置。
 * 通过二分法查找这个位置。
 *
 * 时间复杂度O(KNlogN)
 *
 *
 *
 */

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1,vector<int>(N+1,0));
        for(int i=1;i<=K;i++){
            for(int j=1;j<=N;j++){
                dp[i][j] = j; //初始化为最大尝试次数
            }
        }
        for(int i=2;i<=K;i++){
            for(int j=1;j<=N;j++){
                for(int k=1;k<=j;k++){
                    dp[i][j] = min(dp[i][j],max(dp[i-1][k-1],dp[i][j-k])+1);
                }
            }
        }
        return dp[K][N];
    }
};

class Solution {
    unordered_map<int, int> memo;
    int dp(int K, int N) {
        if (memo.find(N * 100 + K) == memo.end()) {
            int ans;
            if (N == 0) ans = 0;
            else if (K == 1) ans = N;
            else {
                //二分法查找距离交点最近的两个位置，比较找出最小
                int lo = 1, hi = N;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(K-1, x-1);
                    int t2 = dp(K, N-x);

                    if (t1 < t2) lo = x;
                    else if (t1 > t2) hi = x;
                    else lo = hi = x;
                }
                //比较两个位置，找到最小
                ans = 1 + min(max(dp(K-1, lo-1), dp(K, N-lo)),
                              max(dp(K-1, hi-1), dp(K, N-hi)));
            }

            memo[N * 100 + K] = ans;
        }

        return memo[N * 100 + K];
    }
public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};
