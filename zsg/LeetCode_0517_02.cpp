#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) return 0;
        int sum=0;
        bool tag = true,sh=true;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' '&&sh) {
                continue;
            }
            else if (str[i] == '+'&&sh) {
                tag = true;
                sh = false;
            }
            else if (str[i] == '-' && sh) {
                tag = false;
                sh = false;
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                if (sum > (INT_MAX / 10)&&tag) {
                    return INT_MAX;
                }
                else if (sum == (INT_MAX / 10) && tag && (str[i] - '0') > 7) {
                    return INT_MAX;
                }
                else if (sum < (INT_MIN / 10) && tag == false) {
                    return INT_MIN;
                }
                else if (sum == (INT_MAX / 10) && tag == false && (str[i] - '0') > 8) {
                    return INT_MIN;
                }
                else if(tag) {
                    sum = sum * 10 + (str[i] - '0');
                    sh = false;
                }
                else if(tag==false) {
                    sum = sum * 10 - (str[i] - '0');
                    sh = false;
                }
            }else {
                break;
           }
        }
        if (tag) {
            return (signed int)sum;
        }
        else {
            return (unsigned int)sum;
        }
    }
};
int main()
{
    string str = "-2147483649";
    Solution ss;
    ss.myAtoi(str);
}