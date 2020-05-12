#pragma once
#include"entity.h"
using namespace std;

/*
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

class Solution {
public:
	int superEggDrop(int K, int N) {
		if (K == 1)
			return N;
		if (N == 1)
			return 1;
		vector<vector<int> > dp(K + 1, vector<int>(N + 1, N));//K+1行
		//ans(K,N)=1+min_x(max( 碎ans(K-1,x-1), 没碎ans(K, N-x) ))
		//只有0层或1层
		for (int i = 1; i <= K; ++i) {
			dp[i][1] = 1;
			dp[i][0] = 0;
		}
		//只有一个或0个鸡蛋
		for (int j = 1; j <= N; ++j) {
			dp[1][j] = j;
			dp[0][j] = 0;
		}
		//从(2,2)开始
		for (int i = 2; i <= K; ++i) {
			for (int j = 2; j <= N; ++j) {
				//------------暴力遍历
				//for (int x = 1; x <= j; ++x) {
				//	//ans(K,N)=min_x(1+max( 碎ans(K-1,x-1), 没碎ans(K, N-x) ))
				//	dp[i][j] = min( dp[i][j], 1+max(dp[i - 1][x - 1], dp[i][j - x]));
				//}
				//-------------二分查找
				//dp[i - 1][x - 1]是鸡蛋碎的情况，x越大这个值越大
				//dp[i][j - x]是鸡蛋没碎的情况，x越大这个值越小
				//找到dp[i - 1][x - 1]>=dp[i][j - x]的最小x值
				int left = 1;
				int right = j;
				int mid = 0;
				while (left < right) {
					mid = left + (right - left) / 2;
					if (dp[i - 1][mid - 1] < dp[i][j - mid]) {
						left = mid + 1;
					}
					else {
						right = mid;
					}
				}
				dp[i][j]= 1 + max( dp[i - 1][right - 1], dp[i][j - right] );
			}
		}
		return dp[K][N];
	}
};