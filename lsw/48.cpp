class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> m;
        int n = s.size();
        int start = 0, result = 0;
        for (int i = 0; i < n; i++) {
            if (m.find(s[i]) != m.end()) {
                start = max(start, m[s[i]] + 1);
            }
            m[s[i]] = i;
            result = max(result, i - start + 1);
        }
        return result;
    }
};
