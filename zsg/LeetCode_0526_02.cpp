#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        return core(res, n);
    }
    vector<string>& core(vector<string>& res,int n) {
        if (n == 1) {
            string tmp = "()";
            res.push_back(tmp);
            return res;
        }
        vector<string> temp = core(res,n-1);
        for (size_t i = 0; i < temp.size(); i++) {
            string brackets = temp[i];
            res.push_back(brackets);//��ԭ�����������м���x��
            //ͷβ���Ը�����һ������
            string temp_brackets;
            temp_brackets = "()"+ brackets;//ͷ����
            res.push_back(temp_brackets);
            temp_brackets.clear();
            temp_brackets = brackets + "()";//β����
            res.push_back(temp_brackets);
            temp_brackets.clear();
            for (size_t j = 0; j < brackets.size()-1; j++) {
                string bra=brackets;//bra�ݴ�ԭ��������
                if (brackets[j] != brackets[j + 1]) {//��������
                    temp_brackets = bra.insert(j+1,"()");
                    res.push_back(temp_brackets);
                    temp_brackets.clear();
                }
            }
            res = removeDuplicate(res);
        }
        return res;
    }
    vector<string>& removeDuplicate(vector<string>& x) {
        if (x.empty()) return x;
        for (vector<string>::iterator i = x.begin(); i < x.end()-1; i++) {
            for (vector<string>::iterator j = i+1; j < x.end(); j++) {
                if (*i==*j) {
                    x.erase(i);
                }
            }
        }
        return x;
    }
};

int main() {
    int n = 3;
    Solution ss;
    ss.generateParenthesis(n);
    return 0;
}