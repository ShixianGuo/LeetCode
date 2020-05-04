#pragma once
#include"entity.h"

using namespace std;
/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//自己的方法，AC了，但远不如题解，题解方法太多了懒得看了
	int trapLeft(vector<int>& height) {
		int size = height.size();
		if (size < 3) return 0;

		//记录左边最高的index
		int left = -1;
		int ans = 0;

		//开始计算
		for (int i = 0; i < size; ++i) {
			if (height[i] > 0) {
				if (left == -1) {
					left = i;
					continue;
				}

				//如果左边低于右边
				if (height[left] <= height[i]) {
					ans += (i - left - 1)*height[left];//理想的最大
					//不断减去中间的
					for (int j = left + 1; j < i; ++j) {
						ans -= height[j];
					}
					left = i;
				}
				//如果左边高于右边,不管
			}
		}
		return ans;
	}


	int trap(vector<int>& height) {
		int size = height.size();
		if (size < 3) return 0;

		//找到最后的一个最高的以及对应的index
		int max = -1;
		int maxIndex = 0;

		for (int i = 0; i < size; ++i) {
			if (max <= height[i]) {
				max = height[i];
				maxIndex = i;
			}
		}

		//分成两部分计算
		vector<int> v1(height.begin(), height.begin() + maxIndex + 1);
		vector<int> v2(height.begin() + maxIndex, height.end());
		reverse(v2.begin(), v2.end());
		return trapLeft(v1) + trapLeft(v2);


	}
};