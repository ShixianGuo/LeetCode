#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = -1;
        unordered_map<char, int> record;
        int max_len = 0;
        int len = s.length();
        while(right < len - 1) {
            right++;
            record[s[right]]++;
            if(record[s[right]] != 1) {
                while(record[s[left]] == 1 && left < right) {
                    record[s[left]]--;
                    left++;
                }
                record[s[left]]--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

