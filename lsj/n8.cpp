class Solution {
public:
	int myAtoi(string str) {
        int i = 0, bol = 1, res = 0;
        while(i < str.size() && str[i] == ' ') ++i;
        if(i == str.size()) return 0;
        if(str[i] == '-'){ bol = -1; ++i; }
        else if (str[i] == '+') { bol = 1; ++i; }
        while(i < str.size() && str[i] >= '0' && str[i] <= '9') {
            int tmp = str[i] - '0';
            if (bol == 1 && (res > INT_MAX / 10 || res == INT_MAX / 10 && tmp > 7))    return INT_MAX;
            if (bol == -1 && (-res < INT_MIN / 10 || -res == INT_MIN / 10 && tmp >= 8)) return INT_MIN;             
            res = res * 10 + tmp;
            i++;
        }
        if(bol == -1) return -res;
        return res;
	}
};
