#pragma once
#include"entity.h"

using namespace std;

/*
给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。

示例 1:

输入: 5
输出: True
解释:
5的二进制数是: 101
示例 2:

输入: 7
输出: False
解释:
7的二进制数是: 111
示例 3:

输入: 11
输出: False
解释:
11的二进制数是: 1011
 示例 4:

输入: 10
输出: True
解释:
10的二进制数是: 1010

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-number-with-alternating-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	bool hasAlternatingBits(int n) {
		//题解的方法更简单
		long x = n ^ (n >> 1); //x的末尾应该是全1
		//x为long，不然x+1可能溢出
		return (x&(x + 1)) == 0;
	}
	//自己的解法，也AC了
	bool hasAlternatingBits_1(int n) {
		//先确定第一个1
		int bit = 31;
		while (!(n >> bit)) {
			--bit;
		}
		//从bit为开始交替
		int num = 1;
		for (; bit >= 0; --bit) {
			//真的要注意优先级的问题
			if (((n >> bit) & 1) != num) {
				return false;
			}
			//不断颠倒0和1
			num = (!num);
		}
		return true;
	}
};