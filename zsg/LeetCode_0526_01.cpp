#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> sta;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sta.push(s[i]);
            }
            else {
                if (')' == s[i] &&!sta.empty()) {
                    if(sta.top()=='(') sta.pop();
                    else sta.push(s[i]);
                }else if (']' == s[i] && !sta.empty()) {
                    if(sta.top()=='[') sta.pop();
                    else sta.push(s[i]);
                }else if ('}' == s[i] &&!sta.empty()) {
                    if(sta.top() == '{') sta.pop(); 
                    else sta.push(s[i]);
                }
                else {
                    sta.push(s[i]);
                }
            }  
        }
        if (sta.empty()) return true;
        else return false;
    }
};

int main() {
    string s = "(]";
    Solution ss;
    stack<char> sta;
    cout << sta.top() << endl;
    return 0;
}