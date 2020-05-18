class Solution {
public:
    string reverseWords(string s) {
        int idx = 0, srt = 0;
        while (idx < s.size()) {
            if (s[idx] == ' ') {
                reverse(s.begin() + srt, s.begin() + idx);
                srt = idx + 1;
            }
            idx++;
        }
        reverse(s.begin() + srt, s.begin() + idx);

        return s;
    }
};
