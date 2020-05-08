class Solution {
public:
    int reverse(int x) {
        double result = 0;
        while(x != 0) {
            result *= 10;
            result += x % 10;
            if(result < INT_MIN || result > INT_MAX)
                return 0;
            x /= 10;
        }
        return result;
    }
};