#pragma once
#include"entity.h"
using namespace std;

/*
输入一个字符串，打印出该字符串中字符的所有排列。
你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
示例:
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
限制：
1 <= s 的长度 <= 8
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	bool judge(const string &s, int begin, int end) {
		//判断begin~end-1之间有没有元素和end相等
		for (int i = begin; i < end; ++i) {
			if (s[i] == s[end])
				return true;
		}
		return false;
	}
	void help(string& s, int begin, vector<string>& ans) {
		int size = s.size();
		if (begin == size - 1) {
			ans.push_back(s);
			return;
		}
		for (int i = begin; i < size; ++i) {
			//这一步是为了固定第begin位，将begin~size-1之间的元素依次和begin交换
			//不允许后面的元素第二次占据begin位，所以需要判断
			//这一步两个思路：1加一层for循环遍历begin~i-1之间有没有重复，2使用哈希表
			if (i!=begin && judge(s, begin, i))
				continue;
			swap(s[begin], s[i]);
			help(s, begin + 1, ans);
			swap(s[begin], s[i]);
		}
	}
	vector<string> permutation(string s) {
		vector<string> ans;
		int size = s.size();
		if (size==0) return ans;
		if (size == 1) {
			ans.push_back(s);
			return ans;
		}
		help(s, 0, ans);
		return ans;

	}
};

