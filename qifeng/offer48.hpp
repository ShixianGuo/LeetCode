#pragma once
#include"entity.h"

using namespace std;
/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

 

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//看了题解，双指针法+哈希表<char, int>存序号而不是出现次数
	int lengthOfLongestSubstring(string s) {
		int size = s.size();
		if (size < 2) return size;
		int head = 0, tail = 0;
		int index[256];
		memset(index, -1, sizeof(int) * 256);
		int len = 1, num;
		index[s[0]] = 0;
		//已知size>=2
		for (int i = 1; i < size; ++i) {
			//出现序号小于head
			if (index[s[i]] < head) {
				++tail;
				index[s[i]] = i;
				num = tail - head + 1;
				if (len < num)
					len = num;
			}
			else {
				++tail;
				//head直接移动到重复字符的右边
				head = index[s[i]] + 1;
				//更新
				index[s[i]] = i;

			}
		}
		return len;
	}
	
	//自己写的，用队列模拟滑动窗口,AC
	int lengthOfLongestSubstring_1(string s) {
		int count[256] = { 0 };
		int size = s.size();
		queue<char> q;
		int len = 0;
		for (int i = 0; i < size; ++i) {
			if (count[s[i]] == 0) {
				++count[s[i]];
				q.push(s[i]);
				if (len < q.size())
					len = q.size();
			}
			else {
				//因为要求连续，所以重复字符之前的字符全部丢弃掉，并将count--或者直接count=0也行
				while (q.front() != s[i]) {
					--count[q.front()];
					q.pop();
				}
				q.pop();//pop掉先前加入的char
				q.push(s[i]);//push后加入的，count不变
			}
		}
		return len;

	}
};