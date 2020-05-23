#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0)return 0;
        int i = 0,sum=0;
        stack<char> sta;
        vector<int> res = {0};
        while (s[i] == ')') i++;
        int tag = 0;
        for (size_t j = i; j < s.size(); j++) {
            if (s[j] == '(' ) {
               
                sta.push('(');
            }else if(!sta.empty()&&s[j]==')'&&tag==1){
                sum += 2;
                res.push_back(sum + res.back());
            }
            else{//Õ»Îª¿ÕÇÒÎª¡°£©¡±
                sum = 0;
            }
        }
        res.push_back(sum);
        sum = *max_element(res.begin(),res.end());
        return sum;
    }
};

int main() {
    string str = "(()";
    Solution ss;
    ss.longestValidParentheses(str);
    return 0;
}