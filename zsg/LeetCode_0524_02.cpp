#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInt(string& s, int& index) {		// 判断是不是带有正负号的整数
        if (index < s.size() && (s[index] == '-' || s[index] == '+')) index++;
        return isUnsigned(s, index);
    }

    bool isUnsigned(string& s, int& index) { // 判断无符号整数
        int pre = index;
        while (index < s.size()) {
            if (s[index] >= '0' && s[index] <= '9') index++;
            else break;
        }
        return index > pre;
    }

    bool isNumber(string s) {
        if (s.empty()) return false;
        int index = 0;
        while (index < s.size() && s[index] == ' ') index++; // 去掉前面的空格
        bool ans = isInt(s, index);
        if (index < s.size() && s[index] == '.') {
            index++;
            ans = isUnsigned(s, index) || ans; // 如果有小数点，只有前后都没有数字才不对
        }
        if (index < s.size() && s[index] == 'e') {
            index++;
            ans = isInt(s, index) && ans;  // 如果出现指数e，则e的前后都必须要有整数
        }
        while (index < s.size() && s[index] == ' ') index++; // 去掉后面的空格
        return ans && index == s.size();
    }
};
