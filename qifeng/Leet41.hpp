#pragma once
#include"entity.h"
using namespace std;

/*
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
示例 1:
输入: [1,2,0]
输出: 3

示例 2:
输入: [3,4,-1,1]
输出: 2

示例 3:
输入: [7,8,9,11,12]
输出: 1
 
提示：
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		//先寻找1
		int i = 0;
		int size = nums.size();
		for (; i < size; ++i) {
			if (nums[i] == 1) break;
		}
		//如果找不到1，ans=1
		if (i == size)
			return 1;
		//找到1,遍历，将<1变为=1
		if (size == 1)
			return 2;
		for (i = 0; i < size; ++i) {
			if (nums[i] < 1)
				nums[i] = 1;
		}
		//遍历，将元素-1作为下标对应的元素置负
		int tmp;
		for (i = 0; i < size; ++i) {
			tmp = abs(nums[i]) - 1;
			//如果超过size，不可能是ans
			if (tmp >= size)
				continue;
			if (nums[tmp] > 0)
				nums[tmp] *= -1;
		}
		//遍历，寻找第一个不是负的元素的下标
		for (i = 0; i < size; ++i) {
			if (nums[i] > 0) {
				return i + 1;
			}
		}
		return size + 1;
	}
	int firstMissingPositive_1(vector<int>& nums) {
		unordered_set<int> s;
		for (int x : nums) {
			s.insert(x);
		}
		int i = 1;
		for (; i < 0x7fffffff; ++i) {
			if (s.count(i) == 0) {
				return i;
			}
		}
		return i;
	}
};