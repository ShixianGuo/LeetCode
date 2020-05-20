class Solution {
public:
    bool checkPali(string s, int left, int right) {
        while (left < right) {
            if(s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        if(!n) return true;
        int left = 0, right = n-1;
        while(left < right) {
            if(s[left] == s[right]) {
                ++left;
                --right;
            } else return checkPali(s, left+1, right) || checkPali(s, left, right-1);
        }
        return true;
    }
};