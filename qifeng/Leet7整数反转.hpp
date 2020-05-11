#pragma once
#include"entity.h"
using namespace std;

class Solution {
public:
	//思路：存到vector中再取出
	//看完题解：没必要使用vector，同时余数可以为负数
	int limit = 0x7fffffff / 10;
	int reverse(int x) {
		if (x == 0) return 0;
		if (x == (int)0x80000000) return 0;//怎么也想不到还有这种情况
		vector<int> v;
		//先确定是否是负数
		bool negative=false;
		int op = 1;
		if (x < 0) {
			negative = true;
			x *= -1;
			op = -1;
		}
		//放入vector 123->321
		while (x > 0) {
			v.push_back(x % 10);
			x /= 10;
		}
		//放出321
		int ans = 0;
		int size = v.size();
		int i = 0;
		for(;i<size;++i){
			//判断溢出
			if (op*ans > limit) 
				return 0;
			if (op*ans == limit) {
				//如果是负数
				if (!negative&&v[i] > 8)
					return 0;
				//如果是正数
				if (!negative&&v[i] > 7)
					return 0;
			}
			//确保不会溢出，相加
			ans = ans * 10 + op * v[i];
		}
		return ans;
	}
};