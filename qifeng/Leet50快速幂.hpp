#pragma once
#include"entity.h"
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		if (n == 1) return x;
		bool positive = true;
		double ans = 1;
		if (n < 0) {
			positive = false;
			if (n == INT_MIN) {
				++n;
				ans = x;
			}
			n = -n;
		}
		while (n > 0) {
			if (n & 1) {
				ans *= x;
				--n;
			}
			else {
				x *= x;
				n >>= 1;
			}
		}
		return positive ? ans : 1 / ans;

	}
};