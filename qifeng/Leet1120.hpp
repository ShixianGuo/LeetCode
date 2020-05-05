#pragma once
#include"entity.h"
using namespace std;
/*
给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：

字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
每个元音 'a' 后面都只能跟着 'e'
每个元音 'e' 后面只能跟着 'a' 或者是 'i'
每个元音 'i' 后面 不能 再跟着另一个 'i'
每个元音 'o' 后面只能跟着 'i' 或者是 'u'
每个元音 'u' 后面只能跟着 'a'
由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。

示例 1：

输入：n = 1
输出：5
解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
示例 2：

输入：n = 2
输出：10
解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和 "ua"。
示例 3：

输入：n = 5
输出：68
 

提示：

1 <= n <= 2 * 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-vowels-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	int countVowelPermutation(int n) {
		const int M = 1e9 + 7;
		long a = 1, e = 1, i = 1, o = 1, u = 1;
		for (int k = 2; k <= n; k++) {
			long aa = (e + i + u) % M;
			long ee = (a + i) % M;
			long ii = (e + o) % M;
			long oo = i;
			long uu = (o + i) % M;
			a = aa;
			e = ee;
			i = ii;
			o = oo;
			u = uu;
		}
		return (a + e + i + o + u) % M;
	}
};