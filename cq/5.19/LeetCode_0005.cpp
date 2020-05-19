class Solution {
    string palindrome(string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--; r++;
        }
        // 返回以 s[l] 和 s[r] 为中心的最长回文串
        return s.substr(l + 1, r - l - 1);
    }
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            // 以 s[i] 为中心的最长回文子串
            string s1 = palindrome(s, i, i);
            // 以 s[i] 和 s[i+1] 为中心的最长回文子串
            string s2 = palindrome(s, i, i + 1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }
};