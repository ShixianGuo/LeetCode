#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInt(string& s, int& index) {		// �ж��ǲ��Ǵ��������ŵ�����
        if (index < s.size() && (s[index] == '-' || s[index] == '+')) index++;
        return isUnsigned(s, index);
    }

    bool isUnsigned(string& s, int& index) { // �ж��޷�������
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
        while (index < s.size() && s[index] == ' ') index++; // ȥ��ǰ��Ŀո�
        bool ans = isInt(s, index);
        if (index < s.size() && s[index] == '.') {
            index++;
            ans = isUnsigned(s, index) || ans; // �����С���㣬ֻ��ǰ��û�����ֲŲ���
        }
        if (index < s.size() && s[index] == 'e') {
            index++;
            ans = isInt(s, index) && ans;  // �������ָ��e����e��ǰ�󶼱���Ҫ������
        }
        while (index < s.size() && s[index] == ' ') index++; // ȥ������Ŀո�
        return ans && index == s.size();
    }
};
