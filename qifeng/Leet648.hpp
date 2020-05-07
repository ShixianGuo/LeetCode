#pragma once
#include"entity.h"
using namespace std;
/*
编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址。

IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；

同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。

IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。

然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。

同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。

说明: 你可以认为给定的字符串里没有空格或者其他特殊字符。

示例 1:

输入: "172.16.254.1"

输出: "IPv4"

解释: 这是一个有效的 IPv4 地址, 所以返回 "IPv4"。
示例 2:

输入: "2001:0db8:85a3:0:0:8A2E:0370:7334"

输出: "IPv6"

解释: 这是一个有效的 IPv6 地址, 所以返回 "IPv6"。
示例 3:

输入: "256.256.256.256"

输出: "Neither"

解释: 这个地址既不是 IPv4 也不是 IPv6 地址。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-ip-address
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	//测试了好久
	unordered_set<char> s = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','A','B','C','D','E','F' };
	
	bool to_int(string str, int& num) {
		if (str.empty())
			return false;
		num = 0;
		for (char c : str) {
			if (c >= '0'&&c <= '9') {
				num = num * 10 + c - '0';
			}
			else {
				return false;
			}
		}
		//如果是单个0没问题，如果是01则错误
		if (num != 0 && str[0] == '0') {
			return false;
		}
		if (num > 255)
			return false;
		return true;
	}
	bool vaildIPv4(string ip) {
		int size = ip.size();
		if (size > 15)
			return false;
		int begin = 0;
		if (ip[0] == '0')
			return false;
		string str;
		int num;
		int count = 0;
		for (int i = 0; i < size; ++i) {
			if (ip[i] == '.') {
				++count;
				if (count > 3 || i == size - 1)
					return false;
				//抽出子字符串
				str = ip.substr(begin, i - begin);
				//转换int，同时检查对错
				if (!to_int(str, num))
					return false;
				begin = i + 1;
				continue;
			}
		}
		str = ip.substr(begin);
		if (!to_int(str, num))
			return false;
		if (count != 3)
			return false;
		return true;
	}
	bool vaildIPv6(string ip) {
		int size = ip.size();
		if (size > 39)
			return false;
		int begin = 0;
		int count = 0;
		for (int i = 0; i < size; ++i) {
			if (ip[i] == ':') {
				++count;
				//第一个：当：个数过多错误
				//第二个：两冒号之间长度过长
				//第三个：两冒号相邻
				//第四个：冒号在末尾
				if (count >> 7 || i - begin > 4 || i - begin == 0 || i == size - 1)
					return false;
				begin = i + 1;
			}
			//超出16进制，错误
			else if (s.count(ip[i])==0)
				return false;
		}
		if (size - 1 - begin > 3)
			return false;
		if (count != 7)
			return false;
		return true;
	}

	string validIPAddress(string IP) {
		if (vaildIPv4(IP)) {
			return "IPv4";
		}
		if (vaildIPv6(IP)) {
			return "IPv6";
		}
		return "Neither";
	}
};