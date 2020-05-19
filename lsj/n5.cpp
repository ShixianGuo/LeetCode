class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start) {
                start = i - (len - 1) / 2; // a b a [c] c a b a
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    int expand(string s, int left, int right) {
        int le = left, ri = right;
        while(le >= 0 && ri < s.size() && s[le] == s[ri]) {
            le --;
            ri ++;
        }
        return ri - le - 1;
    }
};
