#pragma once
#include"entity.h"
using namespace std;
/*
设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。

示例:

输入: a = 1, b = 1
输出: 2
 

提示：

a, b 均可能是负数或 0
结果不会溢出 32 位整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-without-plus-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	int add(int a, int b) {
		//因为leetcode不允许运算溢出，所以要先转换为unsigned int
		unsigned int ans, carry;
		do {
			ans = a ^ b;
			carry = a & b;
			carry <<= 1;
			a = ans;
			b = carry;
		} while (carry != 0);
		return ans;
	}
};