class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        stack<int> sta; sta.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') sta.push(i);
            else {
                sta.pop();
                if (sta.empty()) sta.push(i);
                else maxlen = max(maxlen, i - sta.top());
            }
        }
        return maxlen;
    }
};
