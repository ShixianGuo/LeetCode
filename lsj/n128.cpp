class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxlen = 0;

        for (auto num : nums) {
            if (s.find(num - 1) != s.end()) continue;
            int len = 1;
            while (s.find(num + 1) != s.end()) {
                num++;
                len++;
            }
            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};
