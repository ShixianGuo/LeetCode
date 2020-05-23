#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ss="";
        while (num != 0) {
            if (num >= 1000) {
                ss=ss+"M";
                num = num - 1000;
            }
            else if (num>=900) {
                ss=ss + "CM";
                num = num - 900;
            }
            else if (num >= 500) {
                ss = ss + "D";
                num = num - 500;
            }
            else if (num >= 400) {
                ss = ss + "CD";
                num = num - 400;
            }
            else if (num >= 100) {
                ss = ss + "C";
                num = num - 100;
            }
            else if (num>=90) {
                ss = ss + "XC";
                num = num - 90;
            }
            else if (num >= 50) {
                ss = ss + "L";
                num = num - 50;
            }
            else if (num >= 40) {
                ss = ss + "XL";
                num = num - 40;
            }
            else if (num >= 10) {
                ss = ss + "X";
                num = num - 10;
            }
            else if (num >= 9) {
                ss = ss + "IX";
                num = num - 9;
            }
            else if (num >= 5) {
                ss = ss + "V";
                num = num - 5;
            }
            else if (num >= 4) {
                ss = ss + "IV";
                num = num - 4;
            }
            else {
                ss = ss + "I";
                num = num - 1;
            }
        }
        return ss;
    }
};