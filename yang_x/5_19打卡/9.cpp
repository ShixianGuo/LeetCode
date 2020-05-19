class Solution {
public:
    bool isPalindrome(int x) {
        string s(to_string(x));
        bool ans = true;
        int i = 0;
        int j = s.length() - 1;
        while (i < j){
            if (s[i] != s[j]){
                ans = false;
                break;
            }
            ++i;
            --j;
        }
        return ans;
    }
};