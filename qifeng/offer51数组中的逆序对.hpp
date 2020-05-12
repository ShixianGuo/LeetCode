#pragma once
#include"entity.h"

using namespace std;

/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
示例 1:
输入: [7,5,6,4]
输出: 5
限制：
0 <= 数组长度 <= 50000
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	//输出left-right中的逆序对，排序结果放在nums中，help只是辅助
	int core(vector<int>& nums, int left, int right, vector<int>& help) {
		if (left >= right)
			return 0;
		int mid = left + ((right - left) >> 1);
		int leftCount = core(nums, left, mid, help);
		int rightCount = core(nums, mid + 1, right, help);
		int i = mid, j = right;
		int h = right;
		int count = 0;
		while (i >= left && j >= mid+1) {
			if (nums[i] > nums[j]) {
				//逆序对个数=后面数组前面还有几个元素
				count += (j - mid);
				help[h--] = nums[i--];
				
			}
			else {
				help[h--] = nums[j--];
			}
		}
		while (i >= left) {
			help[h--] = nums[i--];
		}
		while (j >= mid+1) {
			//count += (j - mid);
			help[h--] = nums[j--];
		}
		copy(help.begin() + left, help.begin() + right + 1, nums.begin() + left);
		return count + leftCount + rightCount;

	}
	int reversePairs(vector<int>& nums) {
		int size = nums.size();
		if (size < 2)
			return 0;
		vector<int> help(size);//辅助
		return core(nums, 0, size - 1, help);
	}
};



//class Solution {
//public:
//	int merge(vector<int>& nums, int begin, int mid, int back, vector<int>& help) {
//		int i = begin;
//		int j = mid + 1;
//		int h = begin;
//		int count = 0;
//		while (i <= mid && j <= back) {
//			if (nums[i] <= nums[j]) {
//				help[h++] = nums[i++];
//				//只有当左边数组元素入列的时候才计算贡献度，不然不好统计
//				count += (j - mid - 1);
//			}
//			else {
//				help[h++] = nums[j++];
//			}
//		}
//
//		while (i <= mid) {
//			help[h++] = nums[i++];
//			count += (j - mid - 1);
//		}
//
//		while (j <= back) {
//			help[h++] = nums[j++];
//		}
//
//		for (int k = begin; k <= back; ++k) {
//			nums[k] = help[k];
//		}
//		return count;
//	}
//
//	int core(vector<int>& nums, int begin, int back, vector<int>& help) {
//		if (begin >= back) return 0;
//		int mid = (begin + back) >> 1;
//		//分
//		int leftCount = core(nums, begin, mid, help);
//		int rightCount = core(nums, mid + 1, back, help);
//		//治
//		return leftCount + rightCount + merge(nums, begin, mid, back, help);
//	}
//
//	int reversePairs(vector<int>& nums) {
//		if (nums.size() < 2) return 0;
//		int n = nums.size();
//		vector<int> help(n);
//		return core(nums, 0, n - 1, help);
//	}
//};