class Solution {
public:
    bool isPalindrome(int x) {
        string ss = to_string(x);
        for (int i = 0; i < ss.size() / 2; i++) {
            if (ss[i] != ss[ss.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
