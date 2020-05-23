#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if (s.empty())return 0;
        int sum = 0;
        vector<int> ss;
        for (int j = 0; j < s.size();j++) {
            switch (s[j])
            {
            case 'I':ss.push_back(1); break;
            case 'V':ss.push_back(5); break;
            case 'X':ss.push_back(10); break;
            case 'L':ss.push_back(50); break;
            case 'C':ss.push_back(100); break;
            case 'D':ss.push_back(500); break;
            case 'M':ss.push_back(1000); break;
            default:
                break;
            }
        }
        for (int i = 0; i< ss.size(); i++) {
            if (ss.size() >= 2) {
                if (i + 1 <= s.size() - 1&&ss[i] < ss[i + 1]) {
                    sum = sum + ss[i + 1] - ss[i];
                    i++;
                }
                else {
                    sum = sum + ss[i];
                }
            }
            else {
                sum = sum + ss[i];
            }
        }
        return sum;
    }
};

int main() {
    string str = "MCMXCIV";
    Solution xx;
    xx.romanToInt(str);
}