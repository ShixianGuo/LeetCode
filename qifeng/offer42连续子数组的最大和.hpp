#pragma once
#include"entity.h"
using namespace std;

/*
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。
示例1:
输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

提示：
1 <= arr.length <= 10^5
-100 <= arr[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//动态规划
		int size = nums.size();
		vector<int> dp(size, INT_MIN);//dp[i]代表以i为结尾的最大和
		dp[0] = nums[0];
		for (int i = 1; i < size; ++i) {
			dp[i] = max(nums[i],dp[i - 1] + nums[i]);
		}

		int max = INT_MIN;
		for (int i = 0; i < size; ++i) {
			if (max < dp[i])
				max = dp[i];
		}
		return max;
	}
};