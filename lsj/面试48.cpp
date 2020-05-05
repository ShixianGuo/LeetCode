class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	// 很常规的做法，保存当前字符的上次出现位置，start 代表不重复字符串的初始位置
        unordered_map<char, int> map;
        int maxLen = 0, start = 0;
        for(int i = 0; i < s.size(); i++) {
            if(map.count(s[i]) != 0) {
                start = max(start, map[s[i]] + 1);
            }
            map[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};
