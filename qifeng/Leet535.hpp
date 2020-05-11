#pragma once
#include"entity.h"

using namespace std;
/*
Leetcode 535
TinyURL是一种URL简化服务， 比如：当你输入一个URL https://leetcode.com/problems/design-tinyurl 时，它将返回一个简化的URL http://tinyurl.com/4e9iAk.

要求：设计一个 TinyURL 的加密 encode 和解密 decode 的方法。你的加密和解密算法如何设计和运作是没有限制的，你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/encode-and-decode-tinyurl
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



class Solution {
public:
	//题目意思好像是生成的URL必定是http://tinyurl.com/xxxx;解密的话也从xxxx解密
	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string key = getKey();
		m[key] = longUrl;
		return (preUrl + key);
	}

	// Decodes a shortened URL to its original URL.
	//解密就是从哈希表中寻找对应的longurl,shortUrl就是key
	string decode(string shortUrl) {
		string key(shortUrl, preUrl.size());
		auto iter = m.find(key);
		if (iter != m.end()) {
			return m[key];
		}
		return nullptr;
	}
private:
	string preUrl = "http://tinyurl.com/";
	string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unordered_map<string, string> m;//<shortUrl, longUrl>
	int count = 0;
	string getKey() {
		string key;
		count++;
		int c = count;
		while (c > 0) {
			--c;
			key += chars[c % 62];
			c /= 62;
		}
		return key;
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));