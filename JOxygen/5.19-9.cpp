class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        vector<int> tmp;
        while(x) {
            tmp.push_back(x % 10);
            x /= 10;
        }
        for(int i = 0; i < tmp.size()/2; i++) {
            if(tmp[i] != tmp[tmp.size()-1-i]) return false;
        }
        return true;
    }
};