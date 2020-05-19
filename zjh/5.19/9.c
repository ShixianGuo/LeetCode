class Solution {
public:
    int getDigit(int num, int divisor){
        if(divisor == 1000 * 1000 * 1000){
            return num / divisor;
        }
        return num % (divisor * 10) / divisor;
    }

    bool isPalindrome(int x) {


        if(x < 0){
            return false;
        }
        string s = to_string(x);
        for(int i = 0, j = s.size() - 1; i < j; ++i, --j){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;


        /*

        if(x < 0){
            return false;
        }
        if(x == 0){
            return true;
        }
        // INT_MAX 2147483647 10 bit
        int msb = 1000 * 1000 * 1000;
        int lsb = 1;
        while(getDigit(x, msb) == 0){
            msb /= 10;
        }
        while(msb > lsb){
            if(getDigit(x, msb) != getDigit(x, lsb)){
                return false;
            }
            msb /= 10;
            lsb *= 10;
        }
        return true;
        */

    }
};
